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

	int C = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'a') C++;
		else C--;
	}

	if (C == 0) {
		cout << "0\n";
		return;
	}

	unordered_map<int, int> keys;
	keys[0] = -1;
	int c = 0;
	int best = n;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'a') c++;
		else c--;

		if (keys.count(c-C)) {
			best = min(best,i-keys[c-C]);
		}
		keys[c] = i;
		// c - x = C
	}
	cout << (best == n ? -1 : best) << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}