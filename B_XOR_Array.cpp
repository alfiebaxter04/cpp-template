#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
template <class T> void _print(const vector<T> &v) {cerr<<"[ ";for(auto& i:v)cerr<<i<<" ";cerr<<"] ";}

void solve() {
	int n, l, r;
	cin >> n >> l >> r;
	
	vector<int> a(n);
	// f(x, y) == P[y] xor P[x-1]
	vector<int> P(n+1, 0);
	int mx = 1;

	for (int i = 1; i <= n; i++) {
		if (i == r) {
			P[i] = P[l-1];
		} else {
			if (mx == P[l-1]) mx++;
			P[i] = mx++;
		}
	}

	// P[r] ^ P[l-1] = 0

	int prev = 0;
	// prev ^ x = P[i]
	for (int i = 1; i <= n; i++) {
		a[i-1] = P[i]^P[i-1];
	}

	for (int d : a) cout << d << " ";
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}