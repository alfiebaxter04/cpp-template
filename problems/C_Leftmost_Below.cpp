#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
template <class T> void _print(const vector<T> &v) {cerr<<"[ ";for(auto& i:v)cerr<<i<<" ";cerr<<"] ";}

void solve() {
	int n;
	cin >> n;
	vector<int> b(n);
	for (int& x : b) cin >> x;

	int mn = 2e9;
	for (int i = 0; i < n; i++) {
		int half = b[i] / 2 + 1;
		if (mn < half) {
			cout << "NO\n";
			return;
		}
		mn = min(mn, b[i]);
	}
	cout << "YES\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}