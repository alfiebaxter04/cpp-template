#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(n);
	for (int& x : a) cin >> x;
	for (int& x : b) cin >> x;

	if (2*k - n <= 0) {
		for (int i = 0; i < n; i++) {
			if (b[i] != -1 && a[i] != b[i]) {
				cout << "NO\n";
				return;
			}
		}
		cout << "YES\n";
	} else {
		set<int> first, second;
		for (int i = n-k; i < k; i++)
			first.insert(a[i]);
		for (int i = n-k; i < k; i++) {
			if (b[i] == -1) continue;
			if (!first.count(b[i]) || second.count(b[i])) {
				cout << "NO\n";
				return;
			}
			second.insert(b[i]);
		}
		for (int i = 0; i < n-k; i++) {
			if (b[i] != -1 && a[i] != b[i]) {
				cout << "NO\n";
				return;
			}
		}
		for (int i = k; i < n; i++) {
			if (b[i] != -1 && a[i] != b[i]) {
				cout << "NO\n";
				return;
			}
		}
		cout << "YES\n";
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}