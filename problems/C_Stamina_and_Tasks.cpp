#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

void solve() {
	int n;
	cin >> n;
	vector<double> c(n), p(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		cin >> p[i];
	}

	double best = 0;
	for (int i = n-1; i >= 0; i--) {
		best = max(best, c[i] + (1-p[i]/100)*best);
	}
	cout << fixed << setprecision(10) << best << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}