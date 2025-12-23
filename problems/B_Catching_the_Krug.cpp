#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
using ll = long long;

void solve() {
	int n, rk, ck, rd, cd;
	cin >> n >> rk >> ck >> rd >> cd;
	// villain is D
	
	int live = 0;
	if (rk < rd) live = max(live, rd);
	if (rk > rd) live = max(live, n-rd);
	if (ck < cd) live = max(live, cd);
	if (ck > cd) live = max(live, n-cd);

	cout << live << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}