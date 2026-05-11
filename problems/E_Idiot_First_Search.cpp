#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

const int MOD = 1e9 + 7;

int parent(auto& g, auto& p, auto& P, int node, int last) {
	P[node] = last;
	if (g[node].empty()) return p[node] = 1;

	int x = 3;
	for (int c : g[node])
		x = (x + parent(g, p, P, c, node)) % MOD;

	return p[node] = x;
}

void cost(auto& g, auto& p, auto& P, auto& ans, int node) {
	ans[node] = (ans[P[node]] + p[node]) % MOD;
	for (int c : g[node])
		cost(g, p, P, ans, c);
}

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> g(n+1);
	g[0].push_back(1);
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		if (u && v) {
			g[i+1].push_back(u);
			g[i+1].push_back(v);
		}
	}
	vector<int> p(n+1, 0), P(n+1, 0);
	parent(g, p, P, 0, -1);
	vector<int> ans(n+1, 0);
	cost(g, p, P, ans, 1);
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
	cout << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}