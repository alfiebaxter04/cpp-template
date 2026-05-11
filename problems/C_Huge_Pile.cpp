#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

void solve() {
	int n, k;
	cin >> n >> k;
	
	int best = -1, L = 0;
	deque<int> q; set<int> done;
	q.push_back(n);
	while (!q.empty()) {
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			int front = q.front(); q.pop_front();
			if (front == k) {
				cout << L << "\n";
				return;
			}
			if (front < k) continue;

			if (!done.count(front/2)) { q.push_back(front / 2); done.insert(front/2); }
			if (!done.count(front/2 + front%2)) { q.push_back(front / 2 + front%2); done.insert(front/2 + front%2); }
		}
		L++;
	}
	cout << "-1\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}