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

	vector<ll> P(n+1, 0), Pabs(n+1, 0);
	for (int i = 0; i < n; i++) {
		P[i+1] = P[i] + a[i];
		Pabs[i+1] = Pabs[i] + abs(a[i]);
	}

	ll best = -P[n]+a[0];
	for (int i = 1; i < n; i++) {
		best = max(best, a[0] + Pabs[i]-Pabs[1] - (P[n]-P[i+1]));
	}
	cout << best << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}