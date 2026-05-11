#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

int mex_max(auto& a) {
	int n = a.size();
	int out = 0;
	int mex = 0, mx = 0;
	set<int> nums;
	for (int i = 0; i < n; i++) {
		nums.insert(a[i]);
		mx = max(mx, a[i]);
		while (nums.count(mex)) mex++;
		out += mx + mex;
	}
	return out;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& x : a) cin >> x;

	sort(a.begin(), a.end());

	map<int, int> f;
	for (int x : a) f[x]++;
	vector<int> b;
	for (auto& [k, v] : f) {
		b.push_back(k);
		f[k]--;
	}
	for (auto it = f.rbegin(); it != f.rend(); it++) {
		for (int i = 0; i < it->second; i++) {
			b.push_back(it->first);
		}
	}

	int A = mex_max(b);
	int MAX = *max_element(b.begin(), b.end());
	for (int i = n-1; i >= 0; i--) {
		if (b[i] == MAX) {
			b.erase(b.begin() + i);
			break;
		}
	}
	b.insert(b.begin(), MAX);
	int B = mex_max(b);

	cout << max(A, B) << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}