#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;

void solve() {
	int n, y, r;
	cin >> n >> y >> r;
	
	int sus = min(n, r + min(n - r, y/2));
	cout << sus << "\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}