#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
using ll = long long;

void solve() {
	string r;
	cin >> r;

	int ops = 0;
	int last = -1;
	int n = r.size();
	for (int i = 0; i < n; i++) {
		char c = r[i];
		if (c == 'u') {
			if (last == -1) {
				r[i] = 's';
				ops++;
				last = i;
			} else {
				int idx = i+i-last;
				if (idx < n && r[idx] == 'u') {
					ops++;
					r[idx] = 's';
				}
			}
		} else if (c == 's') {
			last = i;
		}
	}
	if (r[n-1] == 'u') ops++;
	cout << ops << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}