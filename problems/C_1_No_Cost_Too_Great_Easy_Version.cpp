#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
using ll = long long;

const int MAXN = 200005;
int mp[MAXN];

int here[MAXN];
int cost[MAXN];

void pre() {
	for (int i = 2; i < MAXN; i++) {
		if (mp[i] == 0) {
			for (int j = i; j < MAXN; j += i) {
				if (mp[j] == 0) mp[j] = i;
			}
		}
	}
}

vector<int> fact(int x) {
	vector<int> out;
	while (x > 1) {
		int p = mp[x];
		out.push_back(p);
		while (x % p == 0) x /= p;
	}
	return out;
}

void solve() {
	// if two or more evens -> 0 cost
	// if one even -> 1 cost
	// if 0 even -> at max 2 cost	
	
	// iterate through multiples of primes

	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int& x : a) cin >> x;
	for (int& x : b) cin >> x;

	int mx = *max_element(a.begin(), a.end());

	for (int x : a) {
		vector<int> f1 = fact(x);
		vector<int> f2 = fact(x+1);

		for (int f : f1) here[f]++;
		for (int f : f2) cost[f]++;
	}

	int best = 2;
	for (int i = 2; i <= mx; i++) {
		if (here[i] >= 2) {
			cout << "0\n";
			return;
		}
		if (here[i] && cost[i]) {
			best = 1;
		}
	}

	cout << best << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	pre();
	int t; cin >> t;
	while (t--) solve();
}