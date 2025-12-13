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
    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];

    int l, r;
    vector<pair<int, int>> obs(n);
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        obs[i] = make_pair(l, r);
    }

    vector<pair<int, int>> range(n);

    int mn = 0, mx = 0; // before obstacle 0, h0 = 0
    for (int i = 0; i < n; i++) {
        if (d[i] == 0) {
            // height stays
            // range = [mn, mx]
        } else if (d[i] == 1) {
            // height increases
            mn++, mx++;
        } else { // d[i] == -1
            // could stay or increase
            // so range = [mn, mx+1]
            mx++;
        }

        // intersect with obstacle bounds
        mn = max(mn, obs[i].first);
        mx = min(mx, obs[i].second);

        if (mn > mx) {
            cout << -1 << "\n";
            return;
        }

        range[i] = {mn, mx};
    }

    vector<int> h(n+1);
    h[n] = range[n-1].first;

    for (int i = n - 1; i >= 0; i--) {
        auto [minh, maxh] = range[i];

        if (d[i] == 0) {
            h[i] = h[i+1];
        } else if (d[i] == 1) {
            h[i] = h[i+1] - 1;
        } else {
            if (h[i+1] >= minh && h[i+1] <= maxh) {
                d[i] = 0;
                h[i] = h[i+1];
            } else if (h[i+1] - 1 >= minh && h[i+1] - 1 <= maxh) {
                d[i] = 1;
                h[i] = h[i+1] - 1;
            } else {
                cout << -1 << "\n";
                return;
            }
        }
    }

    for (auto a : h) {
        cout << a << " ";
    }
    cout << "\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}