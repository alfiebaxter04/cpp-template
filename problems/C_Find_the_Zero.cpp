#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

void solve() {
	int n;
	cin >> n;

	for (int i = 1; i < 2*n-2; i += 2) {
		cout << "? " << i << " " << i+1 << endl;
		int ans;
		cin >> ans;

		if (ans == 1) {
			cout << "! " << i << endl;
			return;
		}
	}

	int ans, ans2;
	cout << "? 1 " << 2*n << endl;
	cin >> ans;
	cout << "? 2 " << 2*n << endl;
	cin >> ans2;

	if (ans == 1 || ans2 == 1) {
		cout << "! " << 2*n << endl;
	} else {
		cout << "! " << 2*n-1 << endl;
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}