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

	int l = 0, r = n-1;

	string out = "";

	for (int i = 0; i < n; i++) {
		if (i % 2) {
			if (a[l] < a[r]) {
				l++;
				out += 'L';
			} else {
				r--;
				out += 'R';
			}
		} else {
			if (a[l] > a[r]) {
				l++;
				out += 'L';
			} else {
				r--;
				out += 'R';
			}
		}
	}

	assert(out.size() == n);

	cout << out << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}