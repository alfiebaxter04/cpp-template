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
	int n;
	cin >> n;
	vector<ll> b(n);
	for (int i = 0; i < n; i++) cin >> b[i];
	
	// C: 1, 3, 5
	// A: 2, 3, 2

	// b[3] - b[2] = 
	// f(3, 3) + f(1, 3) - f(1, 2) + f(2, 3) - f(2, 2) = 2
	// f(L, i) != f(L, i-1) when a[i] does not appear in a[L..i-1]
	// terms cancel to 0, then to 1, largest 0 term is f(x, i) and f(x, i-1)
	// so b[i] - b[i-1] = x+1..i = i - 
	// 5..9
	// 0 terms: 0..x	0..3
	// 1 terms: x+1..i	4..10
	// f(x, i-1) = f(x, i) implies a[i] = a[x]
	// diff is i - x
	// diff = i - x
	// x = i - diff

	// b[i] - b[i-1]
	// f(i, i) + f(1, i) - f(1, i-1) + f(2, i) - f(2, i-1) ... 
	// 

	vector<int> out(n);
	out[0] = 1;
	int max_v = 1;
	for (int i = 1; i < n; i++) {
		int diff = b[i] - b[i-1];
		if (i >= diff) {
			out[i] = out[i-diff];
		} else {
			out[i] = max_v + 1;
		}
		max_v = max(max_v, out[i]);
	}

	for (int o : out) cout << o << " ";
	cout << "\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}