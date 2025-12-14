#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;

template <class T> void _print(const vector<T> &v) {
    cerr << "[ ";
    for (auto &i : v) cerr << i << " ";
    cerr << "]";
}

void solve() {
	// 10100011
	// 11000011
	// symmetric
	// even bit count and symmetric
	// 1010
	
	// given X in binary representation
	// X[i] != X[n-i-1] for all set X[i]
	// 01000
	// 00010

	int n;
	cin >> n;
	int bc = __builtin_popcount(n);

	string bin = "";
	while (n) {
		if (n & 1) bin += '1';
		else if (!bin.empty()) bin += '0';
		n >>= 1;
	}

	int sz = bin.size();
	int l = 0, r = sz-1;
	bool flag = true;
	while (l < r) {
		if (bin[l++] != bin[r--]) flag = false;
	}

	if (flag && (bc % 2 == 0)) cout << "YES\n";
	else cout << "NO\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}