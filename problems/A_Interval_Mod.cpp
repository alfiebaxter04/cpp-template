#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

const int INF = 1e15;

void solve() {

	int n, k, p, q;
	cin >> n >> k >> p >> q;

	vector<int> a(n);
	for (int& x : a) cin >> x;

	vector<int> Po(n+1, 0), Pp(n+1, 0), Pq(n+1, 0);
	for (int i = 1; i <= n; i++) {
		int b = a[i-1] % p;
		int c = (a[i-1] % q) % p;
		Po[i] = Po[i-1] + min(b, c);
		Pp[i] = Pp[i-1] + b;
		Pq[i] = Pq[i-1] + c;
	}

	int best = INF;
	for (int i = k; i <= n; i++) {
		int mid = min(Pp[i] - Pp[i-k], Pq[i] - Pq[i-k]);
		int left = Po[i-k];
		int right = Po[n] - Po[i];
		best = min(best, left + mid + right);
	}

	cout << best << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}