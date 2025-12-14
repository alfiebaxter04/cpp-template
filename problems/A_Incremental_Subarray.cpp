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
    int n, m;
    cin >> n >> m;

    int a[m];
    for (int i = 0; i < m; i++) cin >> a[i];
    
    bool incr = true;
    for (int i = 1; i < m; i++) {
        if (a[i] != a[i-1] + 1) {
            cout << 1 << "\n";
            return;
        }
    }

    cout << n - a[m - 1] + 1 << "\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}