#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;

struct chash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> a(n, k+1);

    int c, l, r;
    vector<bool> mex(n, false), mn(n, false);
    for (int i = 0; i < q; i++) {
        cin >> c >> l >> r;
        if (c == 1) {
            for (int j = l-1; j < r; j++) mn[j] = true;
        } else {
            for (int j = l-1; j < r; j++) mex[j] = true;
        }
        
    }
    for (int i = 0; i < n; i++) {
        if (!mex[i] && mn[i]) a[i] = k;
        if (mex[i] && !mn[i]) {
            a[i] = (i+1) % k;
        }
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main() {
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}