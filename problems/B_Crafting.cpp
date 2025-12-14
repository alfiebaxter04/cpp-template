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
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	int low = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < b[i]) low += b[i] - a[i];
	}

	for (int i = 0; i < n; i++) {
		int diff = b[i] - a[i];
		if (a[i] - low + diff < b[i]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}