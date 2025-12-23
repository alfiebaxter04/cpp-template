#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    if (k & 1) {
        for (int i = 0; i < k; i++) cout << n << " ";
    } else {
        for (int i = 0; i < k - 2; i++) cout << n << " ";
        if (__builtin_popcount(n) == 1) {
            cout << n << " " << 0 << " ";
        } else {
            int msb = 31 - __builtin_clz(n);
            
            int wmsb = n ^ (1LL << msb);
            int sec = 31 - __builtin_clz(wmsb);
            ll a = (1LL << msb) | ((1LL << sec) - 1);
            ll b = n ^ a;
            
            cout << a << " " << b << " ";
        }
    }
    cout << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}