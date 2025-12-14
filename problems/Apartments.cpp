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

int main(){
	fastio;
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    // a = desired sizes of applicants
    // b = sizes of apartments

    // a[i] will accept b[j] if b[j] - k <= a[i] <= b[j] + k
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0;
    int ap = 0, bp = 0;

    while (ap < n && bp < m) {
        if (b[bp] + k < a[ap]) {
            // apartment too small
            bp++;
        } else if (b[bp] - k > a[ap]) {
            // desired size too big
            ap++;
        } else {
            ans++;
            ap++;
            bp++;
        }
    }


    cout << ans << "\n";
}