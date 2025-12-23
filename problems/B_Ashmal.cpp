#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	
	vector<string> a(n);
	for (string& x : a) cin >> x;

	string out = "";
	for (string& s : a) {
		string start = s + out;
		string end = out + s;
		out = min(start, end);
	}

	cout << out << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}