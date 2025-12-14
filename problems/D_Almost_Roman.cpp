#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;

void solve() {
	int n, q;
	string s;
	cin >> n >> q >> s;

	int base = 0, potI = 0, potXV = 0, dunno = 0;
	for (int i = n-1; i >= 0; i--) {
		if (s[i] == 'X') base += 10;
		else if (s[i] == 'V') base += 5;
		else {
			if (i+1 < n && (s[i+1] == 'X' || s[i+1] == 'V')) base--;
			else base++;
		}

		if (i+1 < n && s[i] == '?' && (s[i+1] == 'X' || s[i+1] == 'V')) potI++;
		if (i-1 >= 0 && s[i] == '?' && s[i-1] == 'I') potXV++;
		if (s[i] == '?') dunno++;
	}

	int cx, cv, ci;
	for (int i = 0; i < q; i++) {
		cin >> cx >> cv >> ci;

		int ans = base;
		// place as many I's as possible.
		// then V's
		// then X's
		// but want to put I's before V/X

		int ones = min(ci, dunno);
		int fives = min(cv, dunno-ones);
		int tens = min(cx, dunno-ones-fives);

		// how many pairs of "??"
	}
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}