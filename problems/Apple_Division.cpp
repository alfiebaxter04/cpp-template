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
    int n;
    cin >> n;
    ll sum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    if (n == 1) {
        cout << a[0] << "\n";
        return 0;
    }

    ll best = LINF;
    for (int m = 1; m < (1 << n) - 1; m++) {
        ll cur = 0;
        int j = 0, i = m;
        while (i > 0) {
            if (i & 1) {
                cur += a[j];
            }
            j++;
            i >>= 1;
        }
        // s1: cur
        // s2: sum - cur
        // diff: abs(cur - (sum - cur))
        // = abs(2*cur - sum)
        best = min(best, abs(2*cur - sum));
    }

    cout << best << "\n";
}