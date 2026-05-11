#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

void solve() {
	int n, k, K;
	cin >> n >> k;
	vector<int> b(n);
	for (int& x : b) cin >> x;
	cin >> K;

	int l = b[K-1], r = b[K-1];
	int left = 0, right = 0;
	for (int i = K-2; i >= 0; i--) {
		if (b[i] != l) { left++; l = b[i]; }
	}
	for (int i = K; i < n; i++) {
		if (b[i] != r) { right++; r = b[i]; }
	}

	int ops = max(left, right);
	ops += ops%2;
	cout << ops << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}