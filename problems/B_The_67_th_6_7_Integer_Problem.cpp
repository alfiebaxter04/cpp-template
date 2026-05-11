#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

void solve() {
	vector<int> a(7);
	for (int& x : a) cin >> x;
	sort(a.begin(), a.end());
	int sum = a.back();
	for (int i = 0; i < 6; i++) sum += -a[i];
	cout << sum << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}