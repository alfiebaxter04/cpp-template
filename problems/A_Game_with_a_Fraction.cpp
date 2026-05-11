#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

void solve() {
	int p, q;
	cin >> p >> q;
	if (q <= p || 3*p < 2*q) cout << "Alice\n";
	else cout << "Bob\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}