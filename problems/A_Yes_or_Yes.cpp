#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
using ll = long long;

void solve() {
	string s;
	cin >> s;
	int y = 0;
	for (char c : s) {
		if (c == 'Y') y++;
	}
	if (y <= 1) {
		cout << "YES\n";
	}  else {
		cout << "NO\n";
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}