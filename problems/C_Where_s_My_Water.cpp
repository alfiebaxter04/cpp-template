#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

void solve() {
	int n, h;
	cin >> n >> h;

	vector<int> a(n);
	for (int& x : a) cin >> x;

	vector<vector<int>> W(n, vector<int>(n, 0));

	int dirtL = 0, dirtR = 0;
	for (int d = 0; d < n; d++) {
		for (int L = d; L >= 0; L--) {
			dirtL = max(dirtL, a[L]);
			W[d][L] = h - dirtL;
		}
		for (int R = d+1; R < n; R++) {
			dirtR = max(dirtR, a[R]);
			W[d][R] = h - dirtR;
		}
		for ()
	}

}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}