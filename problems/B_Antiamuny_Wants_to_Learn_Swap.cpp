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

	vector<int> I(n+1, 0);
	for (int i = 1; i < n-1; i++) {
		int cond = 0;
		if (a[i-1] > a[i] && a[i] > a[i+1]) cond = 1;
		I[i+2] = I[i+1] + cond;
	}


	int l, r;
	for (int i = 1; i <= q; i++) {
		cin >> l >> r;
		if (r-l+1 <= 2) {
			cout << "YES\n";
		} else {
			int inv = I[r] - I[l+1];
			if (inv) cout << "NO\n";
			else cout << "YES\n";
		}
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}