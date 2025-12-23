#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
using ll = long long;

int n, k;

void solve() {
	cin >> n >> k;
	vector<int> a(n);
	for (int& x : a) cin >> x;

	sort(a.begin(), a.end());
	int MX = a[n-1];

	vector<int> F(4*MX+1, 0), P(4*MX+1, 0);
	for (int x : a) F[x]++;
	for (int i = 0; i < 4*MX; i++) {
		P[i+1] = P[i] + F[i];
	}

	// for a given beauty g,
	// need to delete all lower elements.
	for (int g = a[k]; g >= 1; g--) {
		int div = F[2*g] + F[3*g];
		int less = P[g];
		int more = P[4*g] - P[g+1];
		// debug(g, div, less, more);
		if (less + more - div <= k) {
			cout << g << "\n";
			return;
		}
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}