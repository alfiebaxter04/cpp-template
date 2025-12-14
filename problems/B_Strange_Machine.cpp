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
    int n, q;
    cin >> n >> q;
    string m;
    cin >> m;

    bool hasb = false;
    for (char c : m) if (c == 'B') hasb = true;
    
    int t, idx, cost;
    if (!hasb) {
        while (q--) {
            cin >> t;
            cout << t << "\n";
        }
        return;
    }

    while (q--) {
        cin >> t;
        idx = 0; cost = 0;
        while (t) {
            if (m[idx] == 'A') {
                t--;
            } else {
                t /= 2;
            }
            cost++;
            idx = (idx+1) % n;
        }

        cout << cost << "\n";
    }
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}