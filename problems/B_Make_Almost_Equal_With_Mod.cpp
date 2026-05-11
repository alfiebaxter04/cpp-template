#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

const int MAX_P = 5000;
vector<bool> is_prime(MAX_P+1, true);
vector<int> primes;

void precompute() {
	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i * i <= MAX_P; i++) {
		if (is_prime[i]) {
			for (int j = i * i; j <= MAX_P; j += i)
				is_prime[j] = false;
		}
	}

	int k = 0;
	for (int i = 2; i <= MAX_P; i++) {
		if (is_prime[i]) primes.push_back(i);
	}
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);	
	for (int& x : a) cin >> x;
	
	for (int p : primes) {
		set<int> distinct;
		for (int x : a) {
			distinct.insert(x % p);
		}
		if (distinct.size() == 2) {
			cout << p << "\n";
			return;
		}
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	precompute();
	int t; cin >> t;
	while (t--) solve();
}