#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
template <class T> void _print(const vector<T> &v) {cerr<<"[ ";for(auto& i:v)cerr<<i<<" ";cerr<<"] ";}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int one = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 1) one++;
	}	

	if (!one) {
		cout << "YES\n";
		return;
	}

	bool flag = true;
	sort(a.begin(), a.end());
	for (int i = 1; i < n; i++) {
		if (a[i] - 1 == a[i-1]) flag = false;
	}

	cout << (flag ? "YES\n" : "NO\n");
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}