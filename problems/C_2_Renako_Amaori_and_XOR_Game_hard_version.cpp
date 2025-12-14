#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "debug.cpp"
#endif

using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	
	for (int& x : a) cin >> x;
	for (int& x : b) cin >> x;

	// take XOR of both arrays.
	// equal to XOR of A ^ M
	// look at bits in this.
	// s[i] == 1 then bits of A and M differ. both try to get this
	// s[i] == 0 then A and M both have same parity for that bit
	// higher score is determined by who can get the MSB set bit in A ^ M

	int tot = 0;
	for (int x : a) tot ^= x;
	for (int x : b) tot ^= x;

	if (tot == 0) {
		cout << "Tie\n";
		return;
	}

	int msb = 0, bit = 0;
	while (tot) {
		if (tot & 1) msb = bit;
		tot >>= 1; bit++;
	}

	for (int i = n-1; i >= 0; i--) {
		if ((a[i] & (1 << msb)) != (b[i] & (1 << msb))) {
			if (i & 1) cout << "Mai\n";
			else cout << "Ajisai\n";
			return;
		}
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