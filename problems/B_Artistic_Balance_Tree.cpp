#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int& x : a) cin >> x;
	for (int& x : b) cin >> x;

	int sum = 0;
	sort(a.rbegin(), a.rend());
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			if (m) m--;
			else sum += a[i];
		} else sum += a[i];
	}
	cout << sum << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}