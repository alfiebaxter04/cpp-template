#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;

void solve() {
	int n;
	cin >> n;
	vector<ll> b(n);
	for (int i = 0; i < n; i++) cin >> b[i];
	
	sort(b.rbegin(), b.rend());
	// just maximise the first one

	ll bsum = 0;
	for (int i = 0; i < n; i++) bsum += b[i];

	int best = 0;
	for (int i = 0; i < n; i++) {
		if (b[i] == 0) break;
		if (bsum - (i+1) >= n-1) best = max(best, i+1);
	}

	cout << best << "\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}