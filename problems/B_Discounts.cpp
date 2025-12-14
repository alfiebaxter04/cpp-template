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
	vector<int> a(n), b(k);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < k; i++) cin >> b[i];

	sort(a.rbegin(), a.rend());
	sort(b.begin(), b.end());

	int bp = 0;
	ll cost = 0;
	int i = 0;
	while (i < n) {
		if (bp < k && i+b[bp]-1 < n) {
			cost -= a[i+b[bp]-1];
			for (int j = 0; j < b[bp]; j++)
				cost += a[i++];
			bp++;
		} else {
			cost += a[i++];
		}
	}

	cout << cost << "\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}