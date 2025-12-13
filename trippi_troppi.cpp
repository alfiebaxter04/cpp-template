#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;
using ll = long long;

void solve() {
	string line;
	getline(cin, line);
	
	stringstream ss(line);
	string word;
	
	while (ss >> word) {
		cout << word[0] << "";
	}
	cout << "\n";
}

int32_t main(){
	fastio;
	int t;
	cin >> t;
	cin.ignore();
	
	while (t--) solve();
}