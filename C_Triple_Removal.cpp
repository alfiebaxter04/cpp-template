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


void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n), count(n+1, 0), pairs(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        // count of first i elements
        count[i+1] = count[i] + a[i];
    }
    for (int i = 0; i < n-1; i++) {
        pairs[i+1] = pairs[i];
        if (a[i] == a[i+1]) {
            // how many pairs in first i elements
            pairs[i+1]++;
        }
    }
    pairs[n] = pairs[n-1];

    int l, r;
    while (q--) {
        cin >> l >> r;

        // 1,0,0,1,0,1
        // 1 1 1 2 2 3
        //   L     R
        // 
        int cnt = count[r] - count[l-1];
        if (cnt % 3 != 0 || (r-l+1) % 3 != 0) {
            cout << -1 << "\n";
        } else {
            // if there is a consecutive pair, cost is length/3
            // else length/3 + 1
            int p_count = pairs[r-1] - pairs[l-1];
            int cost = (r - l + 1) / 3;
            if (p_count > 0) cout << cost << "\n";
            else cout << cost + 1 << "\n";
        }
    }

}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}