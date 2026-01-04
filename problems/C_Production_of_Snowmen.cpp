#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n), c(n);
	for (int& x : a) cin >> x;	
	for (int& x : b) cin >> x;	
	for (int& x : c) cin >> x;	
	
	vector<bool> okf(n, true);
	vector<bool> oks(n, true);

	// is it ok for all shift left/right by x
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i] >= b[j]) {
				int shift = (j - i + n) % n;
				okf[shift] = false;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (b[i] >= c[j]) {
				int shift = (j - i + n) % n;
				oks[shift] = false;
			}
		}
	}

	ll cab = 0, cbc = 0;
	for (bool good : okf) {
		if (good) cab++;
	}
	for (bool good : oks) {
		if (good) cbc++;
	}

	cout << cab * cbc * n << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}