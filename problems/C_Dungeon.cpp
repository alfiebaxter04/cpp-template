#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
using ll = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m), c(m);
	for (int& x : a) cin >> x;	
	for (int& x : b) cin >> x;	
	for (int& x : c) cin >> x;	

	map<int, int> swords, bad;
	map<pair<int, int>, int> mons;
	for (int s : a) swords[s]++;
	for (int i = 0; i < m; i++) {
		if (c[i] > 0) mons[{b[i], c[i]}]++;
		else bad[b[i]]++;
	}

	int kill = 0;
	for (auto it = mons.begin(); it != mons.end(); it++) {
		for (int k = 0; k < it->second; k++) {
			auto it_s = swords.lower_bound(it->first.first);
			if (it_s == swords.end()) continue;
			int sword = it_s->first;
			int refund = it->first.second;
			if (refund > sword) {
				if (--swords[sword] == 0) swords.erase(sword);
				swords[refund]++;
			}
			kill++;
		}
	}

	for (auto it = bad.begin(); it != bad.end(); it++) {
		for (int k = 0; k < it->second; k++) {
			auto it_s = swords.lower_bound(it->first);
			if (it_s == swords.end()) continue;
			kill++;
			if (--swords[it_s->first] == 0) swords.erase(it_s->first);
		}
	}

	cout << kill << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}