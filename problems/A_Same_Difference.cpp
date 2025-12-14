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
	string s;
	cin >> n >> s;
	vector<int> freq(26, 0);

	for (char c : s) freq[c-'a']++;

	cout << n - freq[s[n-1]-'a'] << "\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}