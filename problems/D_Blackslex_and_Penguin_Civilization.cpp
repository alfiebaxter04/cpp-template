#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	
	// p0 must be 2^n-1
	// otherwise we will never be counting a bit

	int mx = (1 << n) - 1;

	map<int, vector<int>> tails;
	vector<int> end;
	for (int i = 0; i < mx; i++) {
		int k = mx;
		int s = -1;
		while (k) {
			if ((i & k) == k) {
				s = max(s,k);
			}
			k >>= 1;
		}
		tails[s].push_back(i);
	}

	for (auto& p : tails) {
		sort(p.second.begin(), p.second.end());
	}

	while (mx) {
		cout << mx << " ";
		for (int x : tails[mx]) {
			if (x != mx) cout << x << " ";
		}
		mx >>= 1;
	}


	for (int x : tails[-1]) cout << x << " ";
	cout << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}