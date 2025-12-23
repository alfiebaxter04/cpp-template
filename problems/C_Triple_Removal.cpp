#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
using ll = long long;

void solve() {
	int n, q;
	cin >> n >> q;
	
	vector<int> a(n);
	for (int& x : a) cin >> x;

	// how many adjacents ?

	vector<int> C(n+1, 0), P(n+1, 0);

	for (int i = 0; i < n; i++) {
		C[i+1] = C[i] + a[i];
	}
	for (int i = 1; i < n; i++) {
		P[i+1] = P[i];
		if (a[i] == a[i-1]) {
			P[i+1]++;
		}
	}

	int l, r;
	while (q--) {
		cin >> l >> r;

		int pairs = P[r] - P[l-1];
		int count = C[r] - C[l-1];

		if ((r-l+1) % 3 != 0 || count % 3 != 0) {
			cout << "-1\n";
			continue;
		}

		if (l>1 && a[l-1] == a[l-2]) pairs--;

		if (pairs) {
			cout << (r-l+1)/3 << "\n";
		} else {
			cout << 1 + (r-l+1)/3 << "\n";
		}
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}