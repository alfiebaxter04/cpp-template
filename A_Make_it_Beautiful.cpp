#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
template <class T> void _print(const vector<T> &v) {cerr<<"[ ";for(auto& i:v)cerr<<i<<" ";cerr<<"] ";}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& x : a) cin >> x;
	sort(a.rbegin(), a.rend());
	if (a[0] == a[1]) swap(a[0], a[n-1]);

	if (a[0] == a[n-1]) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		for (int x : a) cout << x << " ";
		cout << "\n";
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}