#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;

struct chash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template <class T> void _print(const vector<T> &v) {
    cerr << "[ ";
    for (auto &i : v) cerr << i << " ";
    cerr << "]";
}

template <class T> void _print(const vector<vector<T>> &v) {
    cerr << "[\n";
    for (auto &row : v) {
        cerr << "  [ ";
        for (auto &val : row) cerr << val << " ";
        cerr << "]\n";
    }
    cerr << "]";
}

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

ll modpow(ll base, ll exp, ll mod = MOD) {
	ll res = 1;
	base %= mod;
	while (exp > 0) {
		if (exp & 1) res = (res * base) % mod;
		base = (base * base) % mod;
		exp >>= 1;
	}
	return res;
}

class SegTree {
public:
    int n;
    vector<int> st;

    SegTree(int _n=0) { init(_n); }
    void init(int _n) {
        n = _n;
        st.assign(4*n, 0);
    }

    void build(const vector<int>& a, int p, int L, int R) {
        if (L == R) {
            st[p] = a[L];
            return;
        }

        int mid = L + (R - L) / 2;
        build(a, p*2, L, mid);
        build(a, p*2+1, mid+1, R);

        st[p] = min(st[p*2], st[p*2+1]);
    }

    void update(vector<int>& a, int p, int L, int R, int idx, int val) {
        if (L == R) {
            a[idx] = val;
            st[p] = val;
            return;
        }

        int mid = L + (R - L) / 2;
        if (idx <= mid) {
            update(a, p*2, L, mid, idx, val);
        } else {
            update(a, p*2+1, mid+1, R, idx, val);
        }

        st[p] = min(st[p*2], st[p*2+1]);
    }

    int query(int p, int L, int R, int ql, int qr) {
        if (ql > R || qr < L) return INF;
        if (R <= qr && L >= ql) return st[p];

        int mid = L + (R - L) / 2;
        int left = query(p*2, L, mid, ql, qr);
        int right = query(p*2+1, mid+1, R, ql, qr);

        return min(left, right);
    }
};

int main(){
	fastio;
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    SegTree ST(n);
    ST.build(a, 1, 0, n-1);

    int x, y, z;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        if (x == 1) {
            ST.update(a, 1, 0, n-1, y, z);
        } else if (x == 2) {
            int res = ST.query(1, 0, n-1, y, z-1);
            cout << res << "\n";
        }
    }
}