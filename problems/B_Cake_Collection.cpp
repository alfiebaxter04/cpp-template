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
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for (int &x : a) cin >> x;

	sort(a.rbegin(), a.rend());
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (ll)a[i] * max(0, m-i);
	}

	cout << ans << "\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}