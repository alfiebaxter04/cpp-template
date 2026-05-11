#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> c(n), S(n, 0);
    for (int& x : c) cin >> x;
    S[n-1] = c[n-1];
    for (int i = n-2; i >= 0; i--) S[i] = min(c[i], S[i+1]);
    int none = 0;
    for (int i = 0; i < n-1; i++) none += max(0LL, c[i] - S[i+1]);
	int mx = none, run = 1;
    for (int i = 0; i < n-1; i++) {
        if (S[i+1] != S[i]) { mx = max(mx, none+run-1); run = 1; }
		else run++;
    }
    mx = max(mx, none+run-1);
    cout << max(mx, none) << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}