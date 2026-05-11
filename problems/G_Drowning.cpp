#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

const int MAXN = 100105;

struct BIT {
	int n; vector<int> tree;
	BIT(int n) : n(n), tree(n+1, 0) {}
	void update(int x, int val) { while (x <= n) { tree[x] += val; x += (x & -x); } }
	int query(int x) { int res = 0; while (x > 0) { res += tree[x]; x -= (x & -x); } return res; }
};

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& x : a) cin >> x;

	int mult = 1;
	vector<int> P(n+1, 0), vals(n+1, 0);
	for (int i = 1; i <= n; i++) {
		P[i] = P[i-1] + mult * a[i-1];
		mult *= -1;
		vals[i] = P[i];
	}

	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());
	int sz = vals.size();

	auto get_id = [&](int val) {
		return lower_bound(vals.begin(), vals.end(), val) - vals.begin() + 1;
	};


	BIT bitO(sz), bitE(sz);
	int out = n;

	for (int L = n; L >= 1; L--) {
		if (L % 2) {
			// odd
			int id = get_id(P[L-1]);
			out += bitO.query(sz) - bitO.query(id);
			bitO.update(get_id(P[L]), 1);
		} else {
			// even
			int id = get_id(P[L-1]);
			out += bitE.query(id-1);
			bitE.update(get_id(P[L]), 1);
		}
	}

	cout << out << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}