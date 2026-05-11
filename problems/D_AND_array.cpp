#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

const int MOD = 1e9 + 7;
const int MAXN = 1000005;

int fact[MAXN];
int invFact[MAXN];

int power(int base, int exp) {
    int res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    
    invFact[MAXN - 1] = power(fact[MAXN - 1], MOD - 2);
    
    for (int i = MAXN - 2; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

int nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}

void solve() {
	int n;
	cin >> n;
	vector<int> b(n);
	for (int& x : b) cin >> x;	
	vector<int> W(n+1, 0), active, out(n);

	for (int c = n; c >= 1; c--) {
		int sum = 0;
		for (int k : active)
			sum = (sum + nCr(k ,c) * W[k]) % MOD;

		W[c] = (b[c-1] - sum + MOD) % MOD;
		if (W[c] > 0) active.push_back(c);
	}

	int mask = 0;
	for (int k : active) mask |= W[k];
	for (int i = 0; i < n; i++) {
		mask ^= W[i];
		cout << mask << " ";
	}
	cout << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	precompute();
	int t; cin >> t;
	while (t--) solve();
}