#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n+1);
	for (int& x : a) cin >> x;

	ll total = accumulate(a.begin(), a.end(), 0);
	ll turns = total / n;
	// need to order the boxes
	// every person has total / n turns
	// the first total % n people have 1 extra turn
	// should use theirs when they have choice between 0 or theirs

	// 0 1 2 3 people
	// 1 2 1 0

	// 3 can never go first as first has 2 turns
	// can split permutation into two sections:
	// n+1 turns, and n turns
	// first section: sum of their boxes = length * (n+1), may need some from box 0

	ll fsum = extra*(turns+1);
	ll extra = total % n;
	// sum of first 'extra' people must be:
	// extra*(turns+1) - a[0] <= x <= extra*(turns+1)

	vector<ll> ways(a[0]+1, 0);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}