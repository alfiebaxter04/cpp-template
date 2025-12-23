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

	sort(a.begin(), a.end());

	// 5, 11, 22
	// answer is a[0] <= x < a[1]
	// 22 % 17 = 5
	// min a[i] for 6 to work:
	// 12 -> 12 % 7 yes
	// 11 -> 11 % 6 yes
	// 10 -> 10

	// a[1] - m >= a[0]

	cout << max(a[0], a[1] - a[0]) << "\n";

	// 5, 9
	// 10, 17
	// 
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}