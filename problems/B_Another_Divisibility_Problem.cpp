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

// given X
// find Y
// x * 10^d(y) + y mod x+y = 0
// even + y mod even/odd + y = 0
// x odd -> y even
// x even -> y even or odd
// x = 42
// 42 * 10^d(y) + y mod 42+y = 0
// y = 50
// 2600 + 50 mod 92 == 0

// x * (10^d(y) - 1) + x + y mod x + y = 0
// 42 * (10 - 1) mod 42 + y = 0
// left side divisible by 3, 9
//


void solve() {
	int y; cin >> y;	
	cout << 8*y << "\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}