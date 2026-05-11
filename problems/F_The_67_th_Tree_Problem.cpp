#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

void solve() {
	int x, y;
	cin >> x >> y;
	// x = even, y = odd

	int nodes = x + y;
	bool good = true;
	if (nodes % 2 == 0 && (x == 0 || x > y)) good = false;
	if (nodes % 2 == 1 && x >= y) good = false;
	if (y == 0) good = false;
	if (!good) { cout << "NO\n"; return; }

	cout << "YES\n"; if (nodes == 1) return;
	int p = 2;

	if (nodes % 2) y--;
	else x--;

	// evens
	while (x>0) {
		cout << "1 " << p << "\n";
		cout << p << " " << p+1 << "\n";
		p += 2;
		x--; y--;
	}
	while (y>0) {
		cout << "1 " << p++ << "\n";
		y--;
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}