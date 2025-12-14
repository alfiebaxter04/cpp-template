#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "debug.cpp"
#endif

using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int fin = 0, latest = -1;
	for (int& x : a) {
		cin >> x;
		fin ^= x;
	}
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		fin ^= t;
		if (a[i] != t) latest = i;
	}

	if (fin == 0) {
		cout << "Tie\n";
	} else {
		if (latest & 1) cout << "Mai\n";
		else cout << "Ajisai\n";
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}