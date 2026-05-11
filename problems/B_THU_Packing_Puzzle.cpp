#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

void solve() {
	int ct, ch, cu;
	cin >> ct >> ch >> cu;

	int width = 0;
	int sx = min(ct, cu);
	width += 4*sx;
	ct -= sx; cu -= sx;
	width += 3*cu;
	if (ct <= 2*ch) {
		width += 2*ct + 3*ch;
	} else {
		width += 2*ct + 3*ch + 1;
	}
	cout << width << "\n";

}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}