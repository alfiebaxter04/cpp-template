#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& x : a) cin >> x;

	vector<int> L(n, 0), R(n, 0);
	vector<int> P(n+1, 0);
	for (int i = 0; i < n; i++) {
		P[i+1] = P[i] + a[i];
	}
	vector<pair<int, int>> X(n);
	for (int i = 0; i < n; i++) {
		X[i] = {P[i], i};
	}
	sort(X.begin(), X.end());
	vector<int> out(n);
	int p = n;
	for (int i = 0; i < n; i++) {
		auto [T, idx] = X[i];
		out[idx] = p--;
	}
	for (int o : out) cout << o << " ";
	cout << "\n";

}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}