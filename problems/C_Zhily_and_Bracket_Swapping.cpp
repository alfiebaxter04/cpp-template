#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

void solve() {
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;

	vector<int> P1(n+1, 0), P2(n+1, 0);
	for (int i = 0; i < n; i++) {
		P1[i+1] = P1[i];
		if (s1[i] == '(') P1[i+1]++;
		else			  P1[i+1]--;

		P2[i+1] = P2[i];
		if (s2[i] == '(') P2[i+1]++;
		else              P2[i+1]--;
	}

	if ((s1[n-1] == '(' || s2[n-1] == '(') || (s1[0] == ')' || s2[0] == ')') || P1[n] + P2[n] != 0 || (abs(P1[n]) % 2 == 1) || (abs(P2[n]) % 2 == 1)) {
		cout << "NO\n";
		return;
	} 

	int A = 0, B = 0;
	for (int i = 0; i < n; i++) {
		if (s1[i] != s2[i]) {
			if (A > B) {
				s2[i] = '(';
				s1[i] = ')';
			} else if (B > A) {
				s1[i] = '(';
				s2[i] = ')';
			}
		}

		if (s1[i] == '(') A++;
		else A--;

		if (s2[i] == '(') B++;
		else B--;

		if (min(A, B) < 0) {
			cout << "NO\n";
			return;
		}
	}	
	cout << "YES\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}