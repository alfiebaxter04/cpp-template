#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
template <class T> void _print(const vector<T> &v) {cerr<<"[ ";for(auto& i:v)cerr<<i<<" ";cerr<<"] ";}

const ll INF = 1e10;

ll offset(int x, int y, int z) {
	vector<int> tmp { x, y, z };
	sort(tmp.begin(), tmp.end());
	return abs(tmp[0] - tmp[1]) + abs(tmp[2] - tmp[1]);
}

ll offset2(int x, int y) {
	ll mean = (x + y) / 2;
	return abs(x - mean) + abs(y - mean);
}

ll f(vector<int>& a, int l, int r, int extra) {
	int n = r - l + 1;
	vector<ll> dp(a.size()+5, 0);

	for (int i = l+1; i < r; i++) {
		ll two = i-1 >= l ? offset2(a[i], a[i-1]) : INF;
		ll three = i-2 >= l ? offset(a[i], a[i-1], a[i-2]) : INF;
		dp[i+2] = min(dp[i] + three, dp[i+1] + two);
	}

	debug(dp);
	return dp[n+2] + extra;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& x : a) cin >> x;

	assert(offset2(1, 5) == 4);
	assert(offset(1,4,9) == 8);

	ll cost = INF;
	cost = min({
		f(a, 1, n-2, offset(a[0], a[n-1], a[n-2])), 
		f(a, 2, n-1, offset(a[0], a[1], a[n-1])), 
		f(a, 1, n-1, offset2(a[0], a[n-1])),
		f(a, 0, n, 0)
	});


	assert(cost < INF);

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