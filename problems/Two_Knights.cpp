#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;
using ll = long long;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;


void solve() {
	
}

int main(){
	fastio;
	int k;
	cin >> k;

	for (ll i = 1; i <= k; i++) {
		ll squares = i*i;
		ll combs = (squares * (squares - 1)) / 2;
		cout << combs - 4 * (i - 1) * (i - 2) << "\n";
	}
}