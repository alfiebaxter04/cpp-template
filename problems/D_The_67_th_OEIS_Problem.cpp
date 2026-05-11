#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

vector<int> pr;

void primes(int n) {
	vector<int> is(n+1, true);
	is[0] = is[1] = false;

	for (int i = 2; i <= n; i++) {
		if (!is[i]) continue;
		for (int j = i + i; j <= n; j += i) {
			is[j] = false;
		}
	}
	for (int i = 2; i <= n; i++) if (is[i]) pr.push_back(i);
}


void solve() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << pr[i] * pr[i+1] << " ";
	}
	cout << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	primes(1000105);
	while (t--) solve();
}