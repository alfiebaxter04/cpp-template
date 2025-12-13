#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
template <class T> void _print(const vector<T> &v) {cerr<<"[ ";for(auto& i:v)cerr<<i<<" ";cerr<<"] ";}

const int MX = 32;
const int INF = 1e9;

void solve() {
	// identity:
	// S = k + pc(x) - pc(y)
	// where x = start number, y = end number
	// so want to minimise pc(y)
	// dp[i][k][c] -> idx (LSB->MSB), used, "are we giving carry to next bit"
	ll n, k;
	cin >> n >> k;

	if (k >= 31) {
		cout << k + __builtin_popcount(n) - 1 << "\n";
		return;
	}

	ll dp[MX+2][MX+2][2];
	for (int i = 0; i <= MX+1; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j][0] = dp[i][j][1] = INF;
		}
	}

	dp[0][0][0] = 0;
	ll minpc = INF;
	for (int i = 0; i <= MX; i++) {
		ll n_bit = (n >> i) & 1;
		for (int u = 0; u <= k; u++) {
			for (int c = 0; c <= 1; c++) {
				if (dp[i][u][c] == INF) continue;
				for (int t = 0; t <= 1; t++) {
					if (u + t > k) continue;

					int sum = n_bit + c + t;
					int res = sum % 2;
					int next_c = sum / 2;

					dp[i+1][u+t][next_c] = min(dp[i+1][u+t][next_c], dp[i][u][c] + res);
				}
			}
		}
	}

	for (int j = 0; j <= k; j++) {
		for (int c = 0; c <= 1; c++) {
			if (dp[MX+1][j][c] != INF) minpc = min(minpc, (ll)dp[MX+1][j][c] + c);
		}
	}

	cout << __builtin_popcount(n) + k - minpc << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}