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
    string water;
    cin >> water;
    int n = water.size();
    if (n == 1) {
        cout << 1 << "\n";
        return;
    }

    vector<string> inf {
        "><", ">*", "*<", "**",
    };
    for (int i = 1; i < n; i++) {
        for (string& z : inf) {
            if (water.compare(i-1, 2, z) == 0) {
                cout << "-1\n";
                return;
            }
        }
    }

    // there is finite path
    int ans = 0;
    // go left
    int p = 0;
    while (p < n && water[p] != '>') {
        p++;
    }
    ans = max(ans, p);

    int p2 = n-1;
    while (p2 >= 0 && water[p2] != '<') {
        p2--;
    }
    ans = max(ans, n-1-p2);

    cout << ans << "\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}