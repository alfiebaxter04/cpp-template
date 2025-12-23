#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
using ll = long long;

void solve() {
	string n;
	int j, k;
	cin >> n >> j >> k;
	j--; k--;
	string s = n;

	while (j--) {
		next_permutation(n.begin(), n.end());
	}
	while (k--) {
		next_permutation(s.begin(), s.end());
	}

	int A = 0;
	for (int i = 0; i < n.size(); i++) {
		if (n[i] == s[i]) A++;
	}
	// debug (n, s);

	cout << A << "A" << s.size()-A << "B\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}