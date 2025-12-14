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

bool ok(const auto& v) {
    for (auto heap : v) {
        if (heap.empty()) {
            return false;
        }
    }
    return true;
}

void solve() {
    map<int, int> m{
        {4, 0},
        {8, 1},
        {15, 2},
        {16, 3},
        {23, 4},
        {42, 5},
    };

    vector<priority_queue<int, vector<int>, greater<int>>> buckets(6);
    int n;
    cin >> n;
    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        buckets[m[t]].push(i);
    }

    int good_count = 0;
    while (ok(buckets)) {
        int min_idx = -1;
        int idx;
        for (int i = 0; i <= 5; i++) {
            while (!buckets[i].empty() && buckets[i].top() <= min_idx) {
                buckets[i].pop();
            }
            if (buckets[i].empty()) {
                cout << n - good_count << "\n";
                return;
            }
            min_idx = buckets[i].top();
            buckets[i].pop();
        }
        good_count += 6;
    }
    cout << n - good_count << "\n";
}

int main(){
	fastio;
	solve();
	return 0;
}