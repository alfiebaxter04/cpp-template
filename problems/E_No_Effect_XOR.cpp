#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
using ll = long long;

void solve() {
	int l, r;
	cin >> l >> r;
	
	// x ^ a -> b;
	// where a and b are within l..r
	// x can only increase l, and decrease r
	// for each number l..r, k, we cannot set 0-bits with sum > r-k
	// similarly cannot unset bits with sum > k-l
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}