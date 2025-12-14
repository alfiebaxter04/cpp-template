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
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(m+2, 0));

    if (a[0] != 0) {
        dp[0][a[0]] = 1;
    } else {
        fill(dp[0].begin(), dp[0].end(), 1);
        dp[0][0] = 0;
        dp[0][m+1] = 0;
    }

    for (int i = 1; i < n; i++) {
        if (a[i] != 0) {
            dp[i][a[i]] = (
                dp[i-1][a[i]-1] % MOD +
                dp[i-1][a[i]] % MOD +
                dp[i-1][a[i]+1] % MOD
            ) % MOD;
        } else {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = (
                    dp[i-1][j-1] % MOD +
                    dp[i-1][j] % MOD + 
                    dp[i-1][j+1] % MOD
                ) % MOD;
            }
        }
    }

    cout << accumulate(dp[n-1].begin(), dp[n-1].end(), 0LL) % MOD << "\n";
}

int main(){
	fastio;
    solve();
	return 0;
}