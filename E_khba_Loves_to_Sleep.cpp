#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
template <class T> void _print(const vector<T> &v) {cerr<<"[ ";for(auto& i:v)cerr<<i<<" ";cerr<<"] ";}

pair<bool, vector<int>> ok(vector<int>& a, int k, int x, int m) {
	vector<int> out;

	int n = a.size();
	int s = 0;
	while (s+m <= a[0]) {
		out.push_back(s++);
		if (--k <= 0) return {true, out};
	}

	for (int i = 1; i < n; i++) {
		for (int j = a[i-1]+m; j <= a[i]-m; j++) {
			if (!out.empty() && j == out.back()) continue;
			out.push_back(j);
			if (--k <= 0) return {true, out};
		}
	}

	int e = x;
	while (e-m >= a[n-1]) {
		out.push_back(e--);
		if (--k <= 0) return {true, out};
	}

	return {k <= 0, out};
}

void solve() {
	int n, k, x;
	cin >> n >> k >> x;
	
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());

	int l = 0, r = 1e9;
	vector<int> out;
	int best = r;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		auto [flag, res] = ok(a, k, x, mid);
		if (flag) {
			l = mid + 1;
			out = res;
		} else {
			r = mid - 1;
		}
	}
	
	for (int o : out) cout << o << " ";
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}