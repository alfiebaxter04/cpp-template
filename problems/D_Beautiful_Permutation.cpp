#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
using ll = long long;

int query(int L, int R) {
	int p, mp;
	cout << "1 " << L << " " << R << endl;
	cin >> p;
	cout << "2 " << L << " " << R << endl;
	cin >> mp;
	return mp - p;
}

void solve() {
	int n; cin >> n;

	int D = query(1, n);
	int ansL;
	int lo = 1, hi = n - D + 1;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (query(1, mid) > 0) {
			ansL = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;	
		}
	}
	cout << "! " << ansL << " " << ansL + D - 1 << endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}