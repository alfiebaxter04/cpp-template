#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& x : a) cin >> x;

	stack<int> stk;
	map<int, int> buffer;
	vector<int> out(n);
	for (int i = 0; i < n; i++) {
		while (!stk.empty() && a[i] < stk.top()) {\
			buffer[stk.top()+1]++;
			stk.pop();
		}
		stk.push(a[i]);
	}
	while (!buffer.empty() && stk.top() > buffer.begin()->first) {
		buffer[stk.top()+1]++;
		stk.pop();
	}
	for (auto it = buffer.begin(); it != buffer.end(); it++) {
		for (int i = 0; i < it->second; i++) stk.push(it->first);
	}
	for (int i = n-1; i >= 0; i--) {
		out[i] = stk.top();
		stk.pop();
	}
	for (int x : out) {
		cout << x << " ";
	}
	cout << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}