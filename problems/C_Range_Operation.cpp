#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
using ll = long long;

int slow(auto& P, auto& a, int n) {
	int best = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j >= 0; j--) {
			best = max(best, P[n] - P[i+1] + P[j] + (i-j+1)*(2+i+j));
		}
	}
	return best;
}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int& x : a) cin >> x;
	
	// (r-l+1)*(l+r) + P[r+1] - P[l-1]
	// lr -ll + l + rr -rl + r
	// rr - ll + l + r + P[r+1] - P[l-1]
	// f(l) = l - ll - P[l-1]
	// g(r) = P[r+1] + rr + r

	vector<ll> P(n+1, 0);
	for (int i = 0; i < n; i++) {
		P[i+1] = P[i] + a[i];
	}

	ll best = -2e18;
	ll f = -2e18, g = -2e18;
	vector<ll> M(n+1);
	for (ll i = 1; i <= n; i++) {
		f = max(f, i - i*i + P[i-1]);
		M[i] = f;
	}
	for (ll i = 1; i <= n; i++) {
		best = max(best, M[i] + i + i*i + P[n] - P[i]);
	}
	cout << best << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}