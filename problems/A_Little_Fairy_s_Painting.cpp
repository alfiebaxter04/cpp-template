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

	// 8 10 15 20 25
	unordered_set<int> u;
	for (int num : a) u.insert(num);
	int c = u.size();
	int prev = -1;

	while (c != prev) {
		if (!u.count(c)) u.insert(c);
		swap(c, prev);
		c = u.size();
	}

	cout << u.size() << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}