#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
template <class T> void _print(const vector<T> &v) {cerr<<"[ ";for(auto& i:v)cerr<<i<<" ";cerr<<"] ";}

void solve() {
	int n; cin >> n;

	map<int, vector<int>> length;
	pair<int, int> start;
	for (int i = 1; i <= n; i++) {
		cout << "? " << i << " " << n << " ";
		for (int j = 1; j <= n; j++) {
			cout << j << " ";
		}
		cout << endl;

		int ans;
		cin >> ans;
		length[ans].push_back(i);
	}

	int dist = length.rbegin()->first;
	vector<int> path;
	path.push_back(length.rbegin()->second[0]);
	while (--dist) {
		for (int c : length[dist]) {
			cout << "? " << path.back() << " 2 " << path.back() << " " << c << endl; 
			int ans;
			cin >> ans;
			if (ans == 2) {
				path.push_back(c);
				break;
			}
		}
	}

	cout << "! " << path.size() << " ";
	for (int p : path) cout << p << " ";
	cout << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}