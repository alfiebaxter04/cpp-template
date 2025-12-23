#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
using ll = long long;

void solve() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int& x : a) cin >> x;
	for (int& x : b) cin >> x;

	if (a[n-1] != b[n-1]) {
		cout << "NO\n";
		return;
	}

	for (int i = n-2; i >= 0; i--) {
		if (!((a[i]^a[i+1]) == b[i] || (a[i]^b[i+1]) == b[i] || a[i] == b[i])) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}