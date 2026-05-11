#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;

int C[35][35];
void precompute() {
    for (int i = 0; i <= 30; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
}

void solve() {
	int n, k;
	cin >> n >> k;

	int ans = 0;
	int bits = 32 - __builtin_clz(n);
	for (int b = 1; b < bits; b++) {
		for (int j = 0; j < b; j++) {
			int popcount = 1 + j;
			if (popcount > k + 1 - b)
				ans += C[b-1][j];
		}
	}

	if (1 + bits - 1 > k) ans++;

	cout << ans << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	precompute();
	int t; cin >> t;
	while (t--) solve();
}