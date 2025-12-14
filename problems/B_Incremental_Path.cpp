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


void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    set<int> b;
    int t;
    int min_n = INF;
    for (int i = 0; i < m; i++) {
        cin >> t;
        b.insert(t);
        min_n = min(min_n, t);
    }

    int p = 1;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == 'A') {
            p++;
            b.insert(p);
        } else {
            p++;
            if (p < min_n) {
                b.insert(p);
                min_n = p;
                while (b.count(p)) p++;
            } else {
                while (b.count(p)) p++;
                b.insert(p);
                while (b.count(p)) p++;
            }
        }
    }

    cout << b.size() << "\n";
    for (int idx : b) cout << idx << " ";
    cout << "\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}