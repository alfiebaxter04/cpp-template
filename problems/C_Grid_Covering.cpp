#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

void solve() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;

	bool bad = (gcd(m, b) != 1) || (gcd(n, a) != 1) || (gcd(m, n) != 1);
	if (bad) cout << "NO\n";
	else cout << "YES\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}