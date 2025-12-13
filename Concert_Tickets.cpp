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

template <class T> void _print(const vector<vector<T>> &v) {
    cerr << "[\n";
    for (auto &row : v) {
        cerr << "  [ ";
        for (auto &val : row) cerr << val << " ";
        cerr << "]\n";
    }
    cerr << "]";
}

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

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    multiset<int> h; // price of each ticket
    vector<int> t(m); // max price for each customer

    int p;
    for (int i = 0; i < n; i++) {
        cin >> p;
        h.insert(p);
    }
    for (int i = 0; i < m; i++) {
        cin >> t[i];
    }

    for (int i = 0; i < m; i++) {
        int maxp = t[i];
        // find most expensive ticket
        // person is willing to pay
        auto it = h.upper_bound(maxp);
        if (it != h.begin()) {
            --it;
            cout << *it << "\n";
            h.erase(it);
        } else {
            cout << -1 << "\n";
        }
    }
}