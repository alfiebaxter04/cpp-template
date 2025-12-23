#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
using ll = long long;


void dfs(auto& g, auto& d, int prev, int node) {
	for (int adj : g[node]) {
		if (adj == prev) continue;
		dfs(g, d, node, adj);
		d[node] += d[adj];
	}
}

void solve() {
	int n, k;
	cin >> n >> k;

	vector<vector<int>> g(n+1);
	vector<int> d(n+1, 1);
	int u, v;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}	

	dfs(g, d, -1, 1);

	// lets root at 1 to start
	// if node subtree size is >= k, can be LCA in all nodes not in subtree
	// if n - subtree size is >= k, can be LCA for all nodes rooted in subtree

	ll ans = n;
	for (int i = 1; i <= n; i++) {
		int sz = d[i];
		if (sz >= k) ans += n-sz;
		if (n-sz >= k) ans += sz;
	}

	cout << ans << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}