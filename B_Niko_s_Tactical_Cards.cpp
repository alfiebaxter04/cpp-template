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
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	ll big = 0, small = 0;
	for (int i = 0; i < n; i++) {
		ll tmp = big;
		big = max({big-a[i], small-a[i], b[i]-big, b[i]-small});
		small = min({small-a[i], tmp-a[i], b[i]-tmp, b[i]-small});
	}

	cout << max(big, small) << "\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}