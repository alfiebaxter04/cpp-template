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

template <class T> void _print(const vector<T> &v) {
    cerr << "[ ";
    for (auto &i : v) cerr << i << " ";
    cerr << "]";
}

template <class T> void _print(const vector<vector<T>> &v) {
    cerr << "[\n";
    for (auto &row : v) {
        cerr << "  [ ";
        for (auto &val : row) cerr << val << " ";
        cerr << "]\n";
    }
    cerr << "]";
}

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

ll modpow(ll base, ll exp, ll mod = MOD) {
	ll res = 1;
	base %= mod;
	while (exp > 0) {
		if (exp & 1) res = (res * base) % mod;
		base = (base * base) % mod;
		exp >>= 1;
	}
	return res;
}

inline ll seqsum(ll n) {
    return n * (n + 1LL) / 2LL;
}

bool ok(int h, int d, int stops) {
    int segments = stops + 1; // if we stop twice, there are 3 intervals to cross
    int q = d / segments; // length of each segment
    int r = d % segments; // How many segments get one extra move

    // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    //       |        |        |
    //    1  2  1  2  3  1  2  3  1  
    //      +1       +1       +1
    // stops = 3, segments = 4
    // q = 2, r = 1

    ll cost = (ll)r * seqsum(q + 1) + (ll)(segments - r) * seqsum(q);
    return cost < h + stops;
}

void solve() {
    int h, d;
    cin >> h >> d;

    int l = 0, r = d - 1;
    int best = d;
    while (l <= r) {
        int stops = l + (r - l) / 2;

        if (ok(h, d, stops)) {
            best = stops;
            r = stops - 1;
        } else {
            l = stops + 1;
        }
    }

    cout << d + best << "\n"; 
}

int main(){
	fastio;
	int t;
	cin >> t;

	while (t--) solve();
	return 0;
}