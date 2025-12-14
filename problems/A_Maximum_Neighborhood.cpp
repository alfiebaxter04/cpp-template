#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;

void solve() {
	int n;
	cin >> n;

	int MX = n*n;
	int out = 0;
	for (int m = MX; m >= max(0, MX-2*n); m--) {
		int left = (m % n != 1) ? m - 1 : 0;
		int right = (m % n != 0) ? m + 1 : 0;
		int up = (m - n >= 1) ? m - n : 0;
		int down = (m + n <= MX) ? m + n : 0;
		out = max(out, m + left + right + up + down);
	}
	cout << out << "\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}