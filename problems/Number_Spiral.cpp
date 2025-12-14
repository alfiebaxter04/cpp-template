#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define newl "\n"

void solve() {
    ll y, x;
    cin >> y >> x;

    ll n = max(x, y);

    if (x == y) {
        ll out = x * x - (x - 1);
        cout << out << newl;
        return;
    }

    if (x > y) {
        if (x % 2 == 0) {
            ll out = (n - 1) * (n - 1) + y;
            cout << out << newl;
        } else {
            ll out = n * n - (y - 1);
            cout << out << newl;
        }
    } else {
        if (y % 2 == 0) {
            ll out = n * n - (x - 1);
            cout << out << newl;
        } else {
            ll out = (n - 1) * (n - 1) + x;
            cout << out << newl;
        }
    }
}

int main() {
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}