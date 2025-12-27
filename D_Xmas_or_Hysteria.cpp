#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
using ll = long long;

void solve() {
	int n, m;
	cin >> n >> m;


	vector<int> h(n);
	for (int& x : h) cin >> x;
	vector<pair<int, int>> elves(n);
	for (int i = 0; i < n; i++) {
		elves[i] = {h[i], i};
	}
	sort(elves.begin(), elves.end());

	if (m > n/2) {
		cout << "-1\n";
		return;
	}

	if (m == 0) {
		ll sum = 0;
		for (int i = 0; i < n-2; i++) sum += elves[i].first;
		if (elves[n-1].first - sum > elves[n-2].first) {
			cout << "-1\n";
			return;
		}
		cout << n-1 << "\n";
		int last = elves[n-1].first;
		int end = -1;
		for (int i = 0; i < n; i++) {
			if (last - elves[i].first <= 0) break;
			cout << elves[i].second+1 << " " << elves[n-1].second+1 << "\n";
			last -= elves[i].first;
			end = i+1;
		}
		for (int i = end; i < n-1; i++) {
			cout << elves[i].second+1 << " " << elves[i+1].second+1 << "\n";
		}
	} else {
		// m = 2:	1,2,3,|4,5,|6,7
		// extra = 3
		int extra = n - 2*m;
		vector<pair<int, int>> ops;
		for (int i = 0; i < extra; i++) {
			ops.push_back({elves[i].second+1, elves[i+1].second+1});
		}

		cout << ops.size() + m << "\n";

		for (auto [x, y] : ops) {
			cout << x << " " << y << "\n";
		}

		for (int i = n-m; i < n; i++) {
			cout << elves[i].second+1 << " " << elves[i-m].second+1 << "\n";
		}
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}