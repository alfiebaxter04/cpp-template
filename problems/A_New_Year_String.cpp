#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
using ll = long long;

void solve() {
	int n;
	string s;
	cin >> n >> s;

	string s25 = "2025";
	string s26 = "2026";
	int c25 = 0, c26 = 0;
	for (int i = 0; i < n-3; i++) {
		if (s.compare(i, 4, s25) == 0) c25++;
		if (s.compare(i, 4, s26) == 0) c26++;
	}

	if (c26 || c25 == 0) {
		cout << "0\n";
	} else if (c25) {
		cout << "1\n";
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}