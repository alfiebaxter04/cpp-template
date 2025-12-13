#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;

void solve() {
	ll n, k;
	cin >> n >> k;
	vector<ll> q(n);
	for (int i = 0; i < n; i++) cin >> q[i];
	map<ll, int> r;
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		r[t]++;
	}

	// x mod y returns values between 0..y-1
	// q[i] * y + r[i] = x
	// maximise these pairs count
	// q[i] * y + r[i] = x  --> y < x since q[i], r[i] >= 1 
	// ^ this is always true.
	// then can make pair if q[i] + r[i] <= k
	// but r[i] < y

	sort(q.begin(), q.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (r.empty()) break;
		ll lim = (k - q[i]) / (q[i] + 1);
		auto it = r.upper_bound(lim);
		if (it != r.begin()) {
			it--;
			ll key = it->first;
			if (--r[key] == 0) r.erase(key);
			ans++;
		}
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