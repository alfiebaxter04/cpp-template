#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
using ll = long long;

void solve() {
	int n;
	string s;
	cin >> n >> s;

	int max = s[0]-'0'+s[n-1]-'0';
	for (int i = 1; i < n-1; i++) {
		if (s[i-1] == '1' && s[i+1] == '1') s[i] = '1';
		max += s[i]-'0';
	}
	int min = max;
	for (int i = 1; i < n-1; i++) {
		if (s[i-1] == '1' && s[i+1] == '1') {
			s[i] = '0';
			min--;
		}
	}
	cout << min << " " << max << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}