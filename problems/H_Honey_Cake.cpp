#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
using ll = long long;

void solve() {
	ll w, h, d, n;
	cin >> w >> h >> d >> n;

	ll a = gcd(w, n);
	n /= a;
	ll b = gcd(h, n);
	n /= b;
	ll c = gcd(d, n);
	n /= c;

	if (n == 1) {
		cout << a-1 << " " << b-1 << " " << c-1 << "\n";
	} else {
		cout << "-1\n";
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}