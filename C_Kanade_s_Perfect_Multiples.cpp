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
	vector<ll> a(n);
	for (auto& x : a) cin >> x;

	// prime 
	set<int> z, found, out;
	for (int x : a) z.insert(x);
	while (!z.empty()) {
		int now = *z.begin();
		out.insert(now);
		for (int d = now; d <= k; d += now) {
			if (!z.count(d) && !found.count(d)) {
				cout << "-1\n";
				return;
			}
			z.erase(d); found.insert(d);
		}
	}
	cout << out.size() << "\n";
	for (int x : out) cout << x << " ";
	cout << "\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}