#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
using ll = long long;

void solve() {
	int n, x, y;
	string s;
	cin >> n >> x >> y >> s;

	vector<int> p(n);
	for (int& x : p) cin >> x;

	ll min_tot = 0;
	int awin = 0, bwin = 0;
	ll amin = 0, bmin = 0;
	for (int i = 0; i < n; i++) {
		min_tot += p[i];
		if (s[i] == '1') {
			bwin++;
			bmin += p[i]/2 + 1;
		} else {
			awin++;
			amin += p[i]/2 + 1;
		}
	}

	if (amin > x || bmin > y || x + y < min_tot) {
		cout << "NO\n";
		return;
	}
	// y = votes for b
	// x = votes for a
	if (awin == 0 && y-x < n) {
		cout << "NO\n";
		return;
	}
	if (bwin == 0 && x-y < n) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}