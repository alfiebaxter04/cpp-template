#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;
using ll = long long;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;


void solve() {
	int x, n;
	cin >> x >> n;
	
	if (n % 2 == 0) {
		cout << 0 << "\n";
	} else {
		cout << x << "\n";
	}
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}