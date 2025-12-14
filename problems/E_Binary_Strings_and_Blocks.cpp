#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;

const ll MOD = 998244353;

ll modpow(ll base, ll exp, ll mod = MOD) {
	ll res = 1;
	base %= mod;
	while (exp > 0) {
		if (exp & 1) res = (res * base) % mod;
		base = (base * base) % mod;
		exp >>= 1;
	}
	return res;
}

void solve() {
	int n, m;
	cin >> n >> m;

	// beautiful if >= 2 blocks
	// if even number: just remove one from end
	// if odd number: remove any middle blocks to join 2 equal digit blocks
	// combinatronics problem?
	// substring only NOT beautiful when 1 block-> all 0's or 1's
	// for a given string -> let length be X
	// beautiful strings are 2^X - 2
	// how to deal with overlap
	// if the overlap contains both zeroes and ones great
	// else the rest of both need atleast one of the other digit

	int l, r;
	for (int q = 0; q < m; q++) {
		cin >> l >> r;


	}
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}