#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;
using ll = long long;

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
    int n, k;
    cin >> n >> k;

    int h[n];
    for (int i = 0; i < n; i++) cin >> h[i];

    vector<ll> dp(n, INF);
    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
           if (i - j < 0) break;
           dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[i-j])); 
        }
    }

    cout << dp[n-1] << "\n";
}