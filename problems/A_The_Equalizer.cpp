#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int& x : a) cin >> x;
	int sum = 0;
	for (int x : a) sum += x;

	if ((sum % 2) || (k*n) % 2 == 0) cout << "YES\n";
	else cout << "NO\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}