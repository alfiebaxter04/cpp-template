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

pair<int, int> closest_new_table(int& now, int& mx) { 
    pair<int, int> leftmost = {1, 1 + 3 * (mx-1)};

    if (mx == 1) {
        mx++;
        return {1, 1};
    }

    if (now == mx) {
        now = 1; mx++;
        return {1, 1 + 3 * (mx - 1)};
    } else {
        now++;
        return {leftmost.first + 3 * (now - 1), leftmost.second - 3 * (now - 1)};
    }
}

pair<int, int> closest_new_table_const(int now, int mx) { 
    pair<int, int> leftmost = {1, 1 + 3 * (mx-1)};

    if (mx == 1) {
        return {1, 1};
    }

    if (now == mx) {
        return {1, 1 + 3 * mx}; 
    } else {
        return {leftmost.first + 3 * now, leftmost.second - 3 * now};
    }
}

int new_table_dist(int now, int mx) {
    if (mx == 1) return 2;

    if (now == mx) {
        return 3 * (mx+1) - 1;
    } else {
        return 3 * mx - 1;
    }
}

struct Comp { 
    bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>> b) const {
        if (a.first != b.first) return a.first > b.first;
        if (a.second.first != b.second.first) return a.second.first > b.second.first;
        return a.second.second > b.second.second;
    }
};

void solve() {
    int n;
    cin >> n;

    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, Comp> seats;

    int this_dist_count = 0;
    int max_this_dist = 1;

    int g;
    for (int i = 0; i < n; i++) {
        cin >> g;
        if (g == 0) {
            // needs closest new table
            int dist = new_table_dist(this_dist_count, max_this_dist);
            auto [x, y] = closest_new_table(this_dist_count, max_this_dist);
            seats.push({dist+1, {x+1, y}});
            seats.push({dist+1, {x, y+1}});
            seats.push({dist+4, {x+1, y+1}});

            cout << x << " " << y << "\n";

        } else if (g == 1) {
            // sits closest seat
            // sit at new table, or a seat in an occupied table

            Comp cmp;
            pair<int, pair<int, int>> t = {
                new_table_dist(this_dist_count, max_this_dist),
                closest_new_table_const(this_dist_count, max_this_dist)
            };
            if (!seats.empty() && cmp(t, seats.top())) {
                // seats.top() is preferred
                
                int dist = seats.top().first;
                auto [x, y] = seats.top().second;
                seats.pop();

                cout << x << " " << y << "\n";
            } else {
                int dist = new_table_dist(this_dist_count, max_this_dist);
                auto [x, y] = closest_new_table(this_dist_count, max_this_dist);
                seats.push({dist+1, {x+1, y}});
                seats.push({dist+1, {x, y+1}});
                seats.push({dist+4, {x+1, y+1}});

                cout << x << " " << y << "\n";
            }

        }
    }
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}