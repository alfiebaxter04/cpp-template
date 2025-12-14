#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;

template <class T> void _print(const vector<T> &v) {
    cerr << "[ ";
    for (auto &i : v) cerr << i << " ";
    cerr << "]";
}

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;

	int wide = 0, run = 0;
	for (char c : s) {
		int d = c - '0';
		if (d == 1) {
			run++;
			wide = max(wide, run);
		} else {
			run = 0;
		}
	}

	if (wide >= k) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";

	vector<int> out(n, -1);
	int low = 1;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') out[i] = low++;
	}
	for (int i = 0; i < n; i++) {
		if (out[i] == -1) out[i] = low++;
	}

	for (int i = 0; i < n; i++) {
		cout << out[i] << " ";
	}
	cout << "\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}