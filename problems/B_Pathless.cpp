#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
template <class T> void _print(const vector<T> &v) {cerr<<"[ ";for(auto& i:v)cerr<<i<<" ";cerr<<"] ";}

void solve() {
	int n, s;
	cin >> n >> s;

	vector<int> a(n);
	for (int& x : a) cin >> x;

	array<int, 3> freq;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		freq[a[i]]++;
	}

	if (sum > s) {
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << "\n";
	} else if (sum == s) {
		cout << "-1\n";
	} else {
		
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