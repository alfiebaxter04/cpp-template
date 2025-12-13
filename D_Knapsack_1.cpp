#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;
using ll = long long;

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


void solve() {
	
}

int main(){
	fastio;
    // N = number of items, W = capacity
    int N, W;
    cin >> N >> W;

    // dp[i][j] = max profit at item i with cap j
    int w, p;
    cin >> w >> p;
    vector<ll> dp(W+1, 0);
    for (int j = w; j <= W; j++) {
        dp[j] = p;
    }

    for (int i = 1; i < N; i++) {
        cin >> w >> p;
        for (int j = W; j >= w; j--) {
            ll take = dp[j-w] + p;
            dp[j] = max(take, dp[j]);
        }
    }

    // debug(dp);

    cout << dp[W] << "\n";
}