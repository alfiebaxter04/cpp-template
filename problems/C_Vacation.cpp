#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;
using ll = long long;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

ll modpow(ll base, ll exp, ll mod = MOD) {
	ll res = 1;
	base %= mod;
	while (exp > 0) {
		if (exp & 1) res = (res * base) % mod;
		base = (base * base) % mod;
		exp >>= 1;
	}
	return res;
}

int main(){
	fastio;
	int n;
	vector<int> prev(3), state(3, 0);
	cin >> n >> prev[0] >> prev[1] >> prev[2];

	for (int i = 1; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		fill(state.begin(), state.end(), 0);

		state[0] = max(prev[1], prev[2]) + a;
		state[1] = max(prev[0], prev[2]) + b;
		state[2] = max(prev[0], prev[1]) + c;

		swap(state, prev);
	}

	cout << *max_element(prev.begin(), prev.end()) << "\n";
}