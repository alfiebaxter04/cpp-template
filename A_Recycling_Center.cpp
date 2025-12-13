#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
template <class T> void _print(const vector<T> &v) {cerr<<"[ ";for(auto& i:v)cerr<<i<<" ";cerr<<"] ";}

void solve() {
	int n, c;
	cin >> n >> c;
	vector<int> t(n);
	for (int& x : t) cin >> x;

	sort(t.begin(), t.end());
	int p = 1;
	int cost = n;
	for (int i = n-1; i >= 0; i--) {
		if (t[i] * p <= c) {
			cost--;
			p <<= 1;
		}
	}
	cout << cost << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}