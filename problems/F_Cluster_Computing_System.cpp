#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "debug.cpp"
#endif

using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> p(n);
	for (int& x : p) cin >> x;

	vector<int> PG(p.begin(), p.end());
	for (int i = n-2; i >= 0; i--) {
		PG[i] = gcd(PG[i+1], PG[i]);
	}

	ll cost = PG[0];
	int g = p[0];
	for (int i = 1; i < n-1; i++) {
		g = gcd(g, p[i]);
		cost += min(g, PG[i]);
	}
	cout << cost << "\n";	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	return 0;
}