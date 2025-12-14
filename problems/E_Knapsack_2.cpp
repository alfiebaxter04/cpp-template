#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;

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

int main(){
	fastio;
    int N, W;
    cin >> N >> W;

    vector<ll> w(N+1), v(N+1);
    ll total = 0;
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
        total += v[i];
    }

    // dp[v] = minimum weight for profit v
    vector<ll> dp(total+1, LINF);
    // at 0th item, min weight for profit 0 is 0.
    dp[0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int val = total; val >= 0; val--) {
            if (val - v[i] >= 0) {
                ll take = dp[val - v[i]] + w[i] <= W ? dp[val - v[i]] + w[i] : LINF;
                dp[val] = min(dp[val], take);
            }
        }
    }

    // debug(dp);

    // answer will be max(dp[N]) != LINF
    for (int val = total; val >= 0; val--) {
        if (dp[val] != LINF) {
            cout << val << "\n";
            return 0;
        }
    }
    return -1;
}