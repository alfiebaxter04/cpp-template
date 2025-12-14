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

template <class K, class V> void _print(const map<K, V> &m) {
    cerr << "{ ";
    for (auto const& [key, val] : m) {
        cerr << key << ":" << val << " ";
    }
    cerr << "}";
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

ll calculate_valid_perimeter(map<int, int> shape) {
    ll ans = 0;
    int side_count = 0;
    for (auto const& [side, count] : shape) {
        ans += (ll)side * count;
        side_count += count;
    }

    // non-degenerate: longest side must be less than sum of other sides
    while (!shape.empty() && 2LL * shape.rbegin()->first >= ans) {
        auto [side, count] = *shape.rbegin();
        side_count -= count;
        ans -= (ll)side * count;
        shape.erase(side);
    }

    return (side_count >= 3) ? ans : 0;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }

    // take every even side, keeping track of odds
    // symmetrical: take even counts of sides
    map<int, int> shape;
    vector<int> singles;
    for (auto [v, f] : freq) {
        if (f % 2 == 0) {
            shape[v] = f;
        } else {
            if (f > 1) {
                shape[v] = f-1;
            }
            singles.push_back(v);
        }
    }
    sort(singles.begin(), singles.end());

    // case 1: no axis
    ll case1 = 0;
    int side_length = 0;
    for (auto [v, f] : shape) {
        case1 += (ll)v * f;
        side_length += f;
    }
    
    // case 2: one odd stick
    ll case2 = case1;
    int case2_count = side_length + 1;
    for (auto s : singles) {
        if (s < case1) {
            case2 = max(case2, case1 + s);
        }
    }

    // case 3: two odd sticks
    ll case3 = case1;
    int case3_count = side_length + 2;
    for (int i = 1; i < singles.size(); i++) {
        if (singles[i] < case1 + singles[i-1]) {
            case3 = max(case3, case1 + singles[i] + singles[i-1]);
        }
    }

    ll ans = 0;
    if (side_length >= 3) ans = max(ans, case1);
    if (case2_count >= 3 && case2 > case1) ans = max(ans, case2);
    if (case3_count >= 3 && case3 > case1) ans = max(ans, case3);

    cout << ans << "\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}