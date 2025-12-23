#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
using ll = long long;

bool check(ll x, ll y, ll k, ll val) {
	while (x--) {
		val -= val / y;
	}
	return val >= k;
}


void solve() {
	ll x, y, k;
	cin >> x >> y >> k;

	if (y == 1) {
		cout << "-1\n";
		return;
	}
	ll l = 1, r = 1e12, b = -1;
	while (l <= r) {
		ll mid = l + (r - l) / 2;
		if (check(x, y, k, mid)) {
			r = mid - 1;
			b = mid;
		} else {
			l = mid + 1;
		}
	}
	cout << b << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}