#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<ll> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	// if k is odd then we can add b[i] to a[i] then do kadanes
	// else just kadanes
	// kadanes:
	// now = max(now + a[i], a[i])

	ll ans = -2e18;
	ll no = -2e18, yes = -2e18;	
	for (int i = 0; i < n; i++) {
		no = max(no + a[i], a[i]);
		yes = max(yes + a[i], no + b[i]);
		if (k % 2) ans = max(ans, yes);
		else ans = max(ans, no);
	}

	cout << ans << "\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}