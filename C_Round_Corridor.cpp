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


void solve() {
    ll n, m;
    ll q;
    cin >> n >> m >> q;

    string p1, p2;
    int sx, ex;
    ll sy, ey;
    for (int i = 0; i < q; i++) {
        cin >> sx >> sy >> ex >> ey;
        if (ex == 2) {
            if (ey > m/2L) {
                p2 = "LEFT";
            } else {
                p2 = "RIGHT";
            }
        } else {
            if (ey > n/2L) {
                p2 = "LEFT";
            } else { 
                p2 = "RIGHT";
            }
        }

        if (sx == 2) {
            if (sy > m/2L) {
                p1 = "LEFT";
            } else {
                p1 = "RIGHT";
            }
        } else {
            if (sy > n/2L) {
                p1 = "LEFT";
            } else { 
                p1 = "RIGHT";
            }
        }

        if (p1 == p2) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

}

int main(){
	fastio;
    solve();
    return 0;
}