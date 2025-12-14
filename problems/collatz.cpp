#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;
using ll = long long;

void solve(ll n) {
	cout << n << " ";
	while (n != 1) {
		if (n % 2 == 0) n /= 2;
		else n = 3 * n + 1;
		
		cout << n << " ";
	}
}

int32_t main(){
	fastio;
	ll n;
	cin >> n;
	
	solve(n);
}