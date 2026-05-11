#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

void solve() {
	int s, k, m;
	cin >> s >> k >> m;

	int flips = m/k;
	int sand;
	if (flips & 1) sand = min(s,k);
	else sand = s;

	cout << max(0LL, sand - (m%k)) << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}