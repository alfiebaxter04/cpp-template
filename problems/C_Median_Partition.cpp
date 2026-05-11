#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

int INF = 1e15;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int &x : a) cin >> x;

	vector<int> b = a;
	sort(b.begin(), b.end());

	int median = b[n/2];
	vector<int> dp(n+1, -INF);
	dp[0] = 0;

	vector<int> PL(n+1, 0), PE(n+1, 0);
	for (int i = 0; i < n; i++) {
		PL[i+1] = PL[i];
		PE[i+1] = PE[i];
		if (a[i] < median) PL[i+1]++;
		if (a[i] == median) PE[i+1]++;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i; j >= 1; j--) {
			int length = i-j+1;
			int countL = PL[i] - PL[j-1];
			int countE = PE[i] - PE[j-1];

			bool c1 = length % 2;
			bool c2 = countL <= (length-1)/2;
			bool c3 = countL + countE >= (length+1)/2;
			if (c1 && c2 && c3) dp[i] = max(dp[i], dp[j-1]+1);
		}
	}
	cout << dp[n] << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}