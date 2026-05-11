#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

const int INF = 1e9;

int dist(int ax, int ay, int bx, int by) {
	return abs(ax - bx) + abs(ay - by);
}

void solve() {
	int n, ax, ay, bx, by;
	cin >> n >> ax >> ay >> bx >> by;

	vector<pair<int, int>> points(n);
	for (pair<int, int>& p : points) cin >> p.first;
	for (pair<int, int>& p : points) cin >> p.second;

	map<int, vector<int>> groups;
	for (auto [x, y] : points) {
		groups[x].push_back(y);
	}
	for (auto& [x, yp] : groups) {
		sort(yp.begin(), yp.end());
	}


	// group by x-coord
	// get mins/max y value from each
	// dp[i][0] = ending column at bottom
	// dp[i][1] = ending column at top

	int px = groups.begin()->first;
	int pmin = groups.begin()->second[0];
	int pmax = groups.begin()->second.back();

	int g = groups.size();
	vector<vector<int>> dp(g, vector<int>(2, INF));
	dp[0][0] = dist(ax, ay, groups.begin()->first, pmax) + abs(pmin-pmax);
	dp[0][1] = dist(ax, ay, groups.begin()->first, pmin) + abs(pmin-pmax);


	auto it = groups.begin();
	for (int i = 1; i < g; i++) {
		++it;
		int x = it->first;
		int mn = it->second[0];
		int mx = it->second.back();

		dp[i][0] = min(
			dp[i-1][1] + dist(px, pmax, x, mx) + abs(mn-mx),
			dp[i-1][0] + dist(px, pmin, x, mx) + abs(mn-mx)
		);

		dp[i][1] = min(
			dp[i-1][1] + dist(px, pmax, x, mn) + abs(mn-mx),
			dp[i-1][0] + dist(px, pmin, x, mn) + abs(mn-mx)
		);

		px = x;
		pmin = mn;
		pmax = mx;
	}

	cout << min(dp[g-1][0] + dist(px, pmin, bx, by), dp[g-1][1] + dist(px, pmax, bx, by)) << "\n";

}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}