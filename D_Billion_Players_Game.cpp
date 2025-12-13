#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;

void solve() {
	int n;
	ll l, r;
	cin >> n >> l >> r;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());

	// Ignore, bet less, bet greater
	// a[i] = 7
	// bet less: p <= a[i]
	// p = 2 -> gain -> a[i] - p -> 5
	// p = 10 -> lose -> a[i] - p -> -3
	// p <= a[i], profit is a[i] - p;
	// for p >= a[i] profit is p - a[i]

	// profit is sum of linear terms (either p - a[i], or a[i] - p).
	// so as a function -> F(p) is linear. 
	// Either lowest at P = L or P = R
	// answer is min(F(l), F(r))
	// Exchange argument:
	// two offers, y and z where y < z
	// if we bet lower on y, and greater on z, profit is (y - p) + (p - z) = y - z
	// since z > y, therefore y - z < 0
	// therefore, bet greater on smaller number, and less on big number
	// gets us:
	// (p - y) + (z - p) = z - y > 0
	
	// if n % 2, find the best split point O(n)

	// do we pair pairs, or pair smallest with greatest etc
	// assume even for argument sake.
	// a1, a2, a3, a4, ... , an
	// take pairs:
	// (a2 - a1) + (a4 - a3) + ... + (an - an-1)
	// a2 + a4 + a6 + ... - a1 - a3 - a5 - ...
	// take mirror:
	// (an - a1) + (an-1 - a2) + (an-2 - a3)
	// an + an-1 + an-2 + ... - a1 - a2 - a3 ...
	// A is sorted, so mirror is better.

	vector<ll> pre(n+1, 0);
	for (int i = 0; i < n; i++)
		pre[i+1] = pre[i] + a[i];

	// case 1: ignore none
	ll best = -2e18;
	for (int i = 0; i <= n; i++) {
		ll left_sum = pre[i] - pre[0]; // 0..i-1
		ll right_sum = pre[n] - pre[i]; // i..n-1

		ll constant = right_sum - left_sum;
		ll gradient = i - (n - i);

		ll L = constant + l * gradient;
		ll R = constant + r * gradient;

		best = max(best, min(L, R));
	}

	for (int i = 0; i < n; i++) {
		ll left_sum = pre[i] - pre[0]; // 0..i-1
		ll right_sum = pre[n] - pre[i+1]; // i+1..n-1

		ll constant = right_sum - left_sum;
		ll gradient = i - (n - i - 1);

		ll L = constant + l * gradient;
		ll R = constant + r * gradient;

		best = max(best, min(L, R));
	}

	cout << best << "\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}