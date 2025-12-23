#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for (int& x : a) cin >> x;

	int tot = 0;
	for (int i = 0; i < n-1; i++) {
		tot += abs(a[i] - a[i+1]);
	}

	int best = tot;
	for (int i = 1; i < n-1; i++) {
		best = min(best, tot - abs(a[i]-a[i-1]) - abs(a[i]-a[i+1]) + abs(a[i-1]-a[i+1]));
	}

	best = min(best, tot - abs(a[0]-a[1]));
	best = min(best, tot - abs(a[n-1]-a[n-2]));

	cout << best << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}