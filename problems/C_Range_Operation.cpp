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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // gain(l, r) = (l+r)*(r-l+1) - p[r] + p[l-1]
    // = r*r - l*l + l + r - p[r] + p[l-1]
    // f(l) = p[l-1] - l*l + l
    // h(r) = p[r] + r*r + r

    vector<int> pre(n+1, 0);
    for (int i = 0; i < n; i++) {
        pre[i+1] = a[i] + pre[i];
    }

    int gap = -1e9;
    priority_queue<pair<int, int>> before;
    for (int i = 0; i < n; i++) {
        int z = i + 1;
        before.push({pre[i] - z*z + z, i});
        pair<int, int> best = before.top();
        int R = z*z + z - pre[i+1];

        gap = max(gap, best.first + R - pre[i+1] + pre[best.second]);

    }

    cout << pre[n] + gap << "\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}