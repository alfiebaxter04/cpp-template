#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

void solve() {
	int n;
	cin >> n;
	if (n == 2) cout << "2\n";
	else if (n == 3) cout << "3\n";
	else if (n % 2 == 0) cout << "0\n";	
	else cout << "1\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}