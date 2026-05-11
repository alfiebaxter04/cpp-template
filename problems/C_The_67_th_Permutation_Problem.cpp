#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

void solve() {
	int n;
	cin >> n;

	int low = 1;
	int high = n + 1;
	for (int i = 0; i < 3*n; i++) {
		if (i % 3 == 0) {
			cout << low++ << " ";
		} else {
			cout << high++ << " ";
		}
	}
	cout << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}