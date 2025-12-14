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
	// bin search but mid = random(l, r)
	// must always be possible to find i if s[i] == 1	
	// 1, 3, 2, 4, 5
	// its not possible if l, r can fall outside where i is
	// if find(3) is stable, there cannot be smaller number on right
	// or greater on left
	// if s[i] == 0 then must NOT be stable.
	// 

	// impossible if there is 101 pattern
	// 

	int n; string s;
	cin >> n >> s;
	s += '1';

	int go = 0, start = -1;
	vector<pair<int, int>> logs;
	int i = 0;
	while (i <= n) {
		if (s[i] == '0') {
			start = i;
			while (s[i] == '0') { i++; go++; }
			logs.push_back({start, i-1});
		} else {
			go = 0; i++;
		}

		if (go == 1) {
			cout << "NO\n";
			return;
		}

	}

	vector<int> p(n);
	iota(p.begin(), p.end(), 1);

	if (logs.empty()) {
		cout << "YES\n";
		for (int d : p) cout << d << " ";
		cout << "\n";
		return;
	}

	for (auto [s, e] : logs) {
		int lol = e+1;
		for (int i = s; i <= e; i++) {
			p[i] = lol--;
		}
	}

	cout << "YES\n";
	for (int d : p) cout << d << " ";
	cout << "\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}