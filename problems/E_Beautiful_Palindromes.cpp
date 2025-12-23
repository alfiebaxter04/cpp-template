#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    vector<int> f(n+1, 0);
    for (int x : a) f[x]++;

    int b = -1;
    for (int i = 1; i <= n; i++) {
        if (f[i] == 0) {
            b = i;
            break;
        }
    }

    if (b == -1) {
        for (int i = 0; i < k; i++) cout << a[n-3 + (i%3)] << " ";
    } else {
        int y = -1;
        for (int i = 1; i <= n; i++) {
            if (i != b && i != a[n-1]) {
                y = i;
                break;
            }
        }
        vector<int> v{b,y,a[n-1]};
        for (int i = 0; i < k; i++) cout << v[i%3] << " ";
    }
    cout << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}