#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
using ll = long long;

void solve() {
	int n, r;
	cin >> n >> r;

	vector<double> ang(n);
	double PI = acos(-1.0);
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		ang[i] = 180 * atan2(y, x) / PI;
		ang[i] += 180;
	}
	sort(ang.begin(), ang.end());
	double best = 0;
	for (int i = 0; i < n-1; i++) {
		best = max(best, abs(ang[i] - ang[(i+1)]));
	}
	debug(ang, best);

	double ans = best * r * r * PI / 360;
	cout << ans << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}