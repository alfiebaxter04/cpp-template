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
    // the gcd cannot be greater than the min element
    // all elements share some prime factor(s)
    // the lower bound for answer is greatest number we can remove all smaller numbers
    // factor p: can split other number into p divisible nubmers if p <= p+(X%p) <= mp
    // 14, 3: 3 <= 5 <= 6
    // 10: 3 <= 4 <= 3 wrong
    // p+(X%p) <= X-p-p-(X%p)
    // x >= 3p + 2 * (X%p)
    // erase all smaller than p, and those p < X < 3p * 2*(X%p)

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    for (auto x : a) cout << x << " ";
    cout << "\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}