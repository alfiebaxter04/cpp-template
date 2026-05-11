#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> a(k), b(n);
	for (int& x : a) cin >> x;
	for (int& x : b) cin >> x;
	
	int ops = 0;
	for (int i = 0; i < n; i++) {
		ops += k+1 - b[i];
	}
	// x[i], i
	vector<pair<int, int>> cringe(n);
	for (int i = 0; i < n; i++) {
		cringe[i] = {b[i], i};
	}
	sort(cringe.rbegin(), cringe.rend());
	cout << ops << "\n";
	for (auto [_, i] : cringe) {
		for (int _ = 0; _ < k+1 - b[i]; _++) {
			cout << i+1 << " ";
		}
	}
	cout << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}