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
    if (n == 1) { cout << "-1\n"; return; }

    vector<int> even, odd;
    int odd = 0, oddn;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) even.push_back(a[i]);
        else odd.push_back(a[i]);

        if (even.size() == 2) { cout << even[0] << " " << even[1] << "\n"; return; }
    }

    if (!odd.empty()) {
        int oddn = odd[0];
        for (int i = 0; i < n; i++) {
            if (a[i] < oddn && (oddn % a[i]) % 2 == 0)
                { cout << a[i] << " " << oddn << "\n"; return; }
            if (a[i] > oddn && (a[i] % oddn) % 2 == 0)
                { cout << oddn << " " << a[i] << "\n"; return; }
        }
    }

    // 5, 11 -> mod is 11 = 11 - 5 = 6
    for (int i = 1; i < (int)odd.size(); i++) {
        if (odd[i] > 2 * odd[i-1]) {
            cout << odd[i-1] << " " << odd[i] << "\n";
            return;
        }
    }

    // ok, nothings worked so far
    // this means we have 1 or 0 even
    // each odd is half or less of next
    // odd[k] > 2^(k-1)
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}