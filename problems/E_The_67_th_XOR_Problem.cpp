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

	int mx = 0;
	for (int x : a) {
		for (int y : a) {
			mx = max(mx, x^y);
		}
	}

	cout << mx << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}