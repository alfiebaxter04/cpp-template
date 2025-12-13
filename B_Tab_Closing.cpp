#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;

void solve() {
	ll a, b, n;
	cin >> a >> b >> n;
	
	if (b >= a) cout << "1\n";
	else if (b*n > a) cout << "2\n";
	else cout << "1\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}