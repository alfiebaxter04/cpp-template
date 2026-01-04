#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
using ll = long long;

void solve() {
	int a, b;
	cin >> a >> b;
	
	int ta = a, tb = b;

	int cost = 1, count = 0, best = 0;

	// a first
	int tturn = ta;
	bool a_turn = true;
	while (tturn >= cost) {
		count++;
		if (a_turn) {
			ta -= cost;
			a_turn = false;
			tturn = tb;
		} else {
			tb -= cost;
			a_turn = true;
			tturn = ta;
		}
		cost *= 2;
	}

	best = count;
	int turn = b;
	cost = 1;
	count = 0;
	a_turn = false;
	while (turn >= cost) {
		count++;
		if (a_turn) {
			a -= cost;
			a_turn = false;
			turn = b;
		} else {
			b -= cost;
			a_turn = true;
			turn = a;
		}
		cost *= 2;
	}

	cout << max(best, count) << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}