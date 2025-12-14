#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
template <class T> void _print(const vector<T> &v) {cerr<<"[ ";for(auto& i:v)cerr<<i<<" ";cerr<<"] ";}

const int INF = -1e9;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int& x : a) cin >> x;

	vector<int> p;
	for (int i = 0; i < n; i++) {
		if (p.empty() || a[i] > a[p.back()])
			p.push_back(i);
	}
	p.push_back(n);

	vector<vector<int>> dp(k+1, vector<int>(k+1, INF));
	dp[0][0] = 0;

	vector<int> su(k+1);

	int ans = 0;
	for (int i = 0; i < p.size() - 1; i++) {
		fill(su.begin(), su.end(), INF);

		for (int v = 0; v <= k; v++) {
			for (int c = 0; c <= k; c++) {
				su[c] = max(su[c], dp[v][c]);
			}
		}

		for (int v = 0; v <= a[p[i]]; v++) {
			for (int c = 0; c + v <= k; c++) {
				if (su[c] != INF)
					dp[v][c+v] = max(dp[v][c+v], su[c]);
			}
			for (int c = 0; c <= k; c++) {
				if (dp[v][c] != INF)
					dp[v][c] += v * (p[i+1] - p[i]);
				ans = max(ans, dp[v][c]);
			}
		}
	}

	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}