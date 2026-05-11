#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

const int MOD = 676767677;

int fact(int n) {
	if (n == 1) return 1;
	return fact(n-1) * n;
}

void solve() {
	int n, m;
	cin >> n >> m;

	vector<int> b(n);
	for (int& x : b) cin >> x;

	vector<vector<int>> idx(m);
	for (int i = 0; i < n; i++) {
		idx[b[i]].push_back(i);
	}

	int ways = 1;
	int ppl = idx[0].size();
	for (int i = 1; i < m; i++) {
		for (int loc : idx[i]) {
			bool left_g = loc-1 < 0 ? true : b[loc-1] > b[loc];
			bool right_g = loc+1 >= n ? true : b[loc+1] > b[loc];
			if (left_g && right_g) {
				cout << "0\n";
				return;
			}
			ppl++;
		}
	}
	cout << ways << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}