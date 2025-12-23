#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
using ll = long long;

int query(set<int>& args) {
	cout << "? " << args.size() << " ";
	for (int x : args) cout << x << " ";
	cout << endl;
	int MAD;
	cin >> MAD;
	return MAD;
}

void solve() {
	int n;
	cin >> n;
	
	int q = 0;
	vector<int> out(2*n, -1);
	set<int> idxs;
	idxs.insert(1);
	for (int i = 2; i <= 2*n; i++) {
		idxs.insert(i);
		int mad = query(idxs);
		if (mad > 0) {
			out[i-1] = mad;
			idxs.erase(i);
		}
		q++;
	}

	idxs.clear();
	idxs.insert(2*n);
	for (int i = 2*n-1; i >= 1; i--) {
		idxs.insert(i);
		if (out[i-1] != -1) continue;
		int mad = query(idxs);
		if (mad > 0) {
			out[i-1] = mad;
			idxs.erase(i);
		}
		q++;
	}

	cout << "! ";
	for (int o : out) {
		cout << o << " ";	
	}
	assert(q <= 3*n);
	cout << endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}