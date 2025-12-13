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

// .sps.
// p: 1,2,3
// s: 4,3,2,1

// .ps.
// .sp.
// 

void solve() {
	int n; string x;
	cin >> n >> x;

	int s = 0, p = 0;
	if (x[0] == 's') s--;
	if (x[n-1] == 'p') p--;
	for (int i = 0; i < n; i++) {
		if (x[i] == 's') s++;
		else if (x[i] == 'p') p++;
	}
	
	if (p == 0 || s == 0) cout << "YES\n";
	else cout << "NO\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}