#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
using ll = long long;

void solve() {
	int l, a, b;
	cin >> l >> a >> b;

	int best = 0;
	for (int i = 0; i <= 10000; i++) {
		best = max(best, a);
		a = (a + b) % l;
	}

	cout << best << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}