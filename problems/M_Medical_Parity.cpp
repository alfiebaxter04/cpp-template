#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
using ll = long long;

int dp[0500][2];

void solve() {
	string x, y;
	cin >> x >> y;
	int n = x.size();

	dp[0][1] = 1e9;
		
	for (int i = 0; i < n; i++) {
		for (int p = 0; p <= 1; p++) {
			int dx = x[i] - '0';
			int dy = y[i] - '0';
			dp[i+1][p] = min(dp[i][p^1] + (dy^p) + (dx^1), dp[i][p] + dx + (dy^p));
		}
	}

	cout << min(dp[n][0], dp[n][1]) << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}