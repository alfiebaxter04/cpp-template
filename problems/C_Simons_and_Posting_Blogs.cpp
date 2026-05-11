#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

void solve() {
	int n;
	cin >> n;

	vector<vector<int>> L(n);

	for (int i = 0, sz; i < n; i++) {
		cin >> sz;
		vector<int> raw(sz);
		for (int l = sz-1; l >= 0; l--)
			cin >> raw[l];

		set<int> help;
		for (int x : raw) {
			if (!help.count(x))
				L[i].push_back(x);
			help.insert(x);
		}
	}

	vector<bool> done(n, false);
	set<int> seen;

	int next_idx;
	for (int _ = 0; _ < n; _++) {
		next_idx = -1;
		vector<int> next_vec;
		for (int i = 0; i < n; i++) {
			if (done[i]) continue;

			vector<int> filtered;
			for (int l : L[i])
				if (!seen.count(l)) filtered.push_back(l);

			if (next_idx == -1 || filtered < next_vec) {
				next_vec = filtered;
				next_idx = i;
			}
		}

		done[next_idx] = true;
		for (int l : next_vec) {
			cout << l << " ";
			seen.insert(l);
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