#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;

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

int main(){
	fastio;
    int n;
    cin >> n;

    vector<vector<int>> cb(n, vector<int>(n, 0));
    deque<pair<int, int>> q;
    q.push_back({0, 0});
    const pair<int, int> dirs[8] = {
        {-2, 1},
        {-2, -1}, 
        {2, 1}, 
        {2, -1},
        {1, 2},
        {-1, 2},
        {1, -2},
        {-1, -2}
    };

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            auto [x, y] = q.front();
            q.pop_front();

            for (auto [dx, dy] : dirs) {
                if (x+dx >= 0 && x+dx < n && y+dy >= 0 && y+dy < n) {
                    if (cb[x+dx][y+dy] == 0 && !(x+dx == 0 && y+dy == 0)) {
                        cb[x+dx][y+dy] = cb[x][y] + 1;
                        q.push_back({x+dx, y+dy});
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << cb[i][j] << " ";
        }
        cout << "\n";
    }
}