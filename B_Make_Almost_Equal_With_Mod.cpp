#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
template <class T> void _print(const vector<T> &v) {cerr<<"[ ";for(auto& i:v)cerr<<i<<" ";cerr<<"] ";}

void solve() {
	int n;
	cin >> n;
	vector<ll> a(n);
	for (ll &x : a) cin >> x;
	
	ll bit = 0;
	bool t, f;
	while (1) {
		t = false;
		f = false;

		for (int i = 0; i < n; i++) {
			if (a[i] & (1LL << bit)) t = true;
			else f = true;
		}
		if (t && f) {
			cout << (1LL << (bit+1)) << "\n";
			return;
		}

		bit++;
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