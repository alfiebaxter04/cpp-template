#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int& x : a) cin >> x;
	for (int& x : b) cin >> x;

	vector<int> loc(n);
	for (int i = 0; i < n; i++) {
		loc[a[i]-1] = i;
	}

	int last = -1;
	for (int i = 0; i < n; i++) {
		if (b[i] > n || loc[b[i]-1] < last) {
			cout << "NO\n";
			return;
		}
		last = loc[b[i]-1];
	}

	cout << "YES\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}