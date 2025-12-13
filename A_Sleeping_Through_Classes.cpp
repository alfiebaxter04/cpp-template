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
	cin >> n >> k;
	string s;
	cin >> s;

	int dim = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') dim = k;
		else dim--;
		if (dim < 0) ans++;
	}
	cout << ans << "\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}