#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;
using ll = long long;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;


void solve() {
    int x, y;
    cin >> x >> y;

    if (y > x) {
        cout << 2 << "\n";
    } else if (x == y || x - y == 1 || y == 1) {
        cout << -1 << "\n";
    } else {
        cout << 3 << "\n";
    }

    // x - n, y - (n + k), x - (x - n)
    // n >= 1, k > n, x > k + n
    // n >= 1, k >= 2, x >= 3

}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}