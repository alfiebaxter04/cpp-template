#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int& x : a) cin >> x;

	for (int i = n-2; i >= 0; i--) {
		if (a[i+1] >= 0) 
			a[i] += a[i+1];
	}
	int ans = 0;
	for (int x : a) if (x > 0) ans++;
	cout << ans << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}