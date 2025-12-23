#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	int count = 0;
	int minx = 1e9, maxy = -1e9, maxx = -1e9, miny = 1e9;
	int maxl = -1e9, minl = 1e9, maxr = -1e9, minr = 1e9;

	char c;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c;
			if (c == '.') continue;
			minx = min(minx, j);
			miny = min(miny, i);
			maxx = max(maxx, j);
			maxy = max(maxy, i);

			maxl = max(maxl, i-j);
			minl = min(minl, i-j);
			maxr = max(maxr, i+j);
			minr = min(minr, i+j);
			count++;
		}
	}

	bool flag = false;

	// no black
	if (!count) flag = true;

	// 2x2 box
	if (maxy - miny <= 1 && maxx - minx <= 1) flag = true;

	// diagonal
	if (maxl - minl <= 1) flag = true;
	if (maxr - minr <= 1) flag = true;

	cout << (flag ? "YES\n" : "NO\n");
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}