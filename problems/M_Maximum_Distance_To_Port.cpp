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
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> type(n);
    for (int i = 0; i < n; i++) cin >> type[i];
    vector<vector<int>> g(n);

    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    vector<int> out(k, 0);
    queue<int> q;
    q.push(0);

    vector<bool> vis(n, false);
    vis[0] = true;

    int dist = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            int c = q.front(); q.pop();
            out[type[c]-1] = dist;
            for (int adj : g[c]) {
                if (!vis[adj]) {
                    vis[adj] = true;
                    q.push(adj);
                }
            }
        }
        dist++;
    }

    for (int o : out) cout << o << " ";
    cout << "\n";
}

int main(){
	fastio;
	solve();
	return 0;
}