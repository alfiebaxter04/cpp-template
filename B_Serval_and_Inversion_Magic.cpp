#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;

void solve() {
	int n;
	string s;
	cin >> n >> s;
	
	int blocks = 0; bool in = false;
	for (int i = 0; i < n/2; i++) {
		if (s[i] != s[n-i-1]) {
			if (!in) blocks++;
			in = true;
		} else {
			in = false;
		}
	}

	cout << ((blocks <= 1) ? "Yes\n" : "No\n");
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}