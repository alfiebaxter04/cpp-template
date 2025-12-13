#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;

vector<pair<int, int>> dd { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int tag = 0;

struct DSU {
    vector<int> parent, size;
	int num_sets;
    DSU(int n) {
        parent.resize(n); size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
		num_sets = n;
    }

    int find_set(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
			num_sets--;
        }
    }
	int get_sets() { return num_sets; }
};

void dfs(auto& grid, auto& vis, DSU& dsu, int i, int j) {
	int n = grid.size(), m = grid[0].size();
	vis[i][j] = 1;
	for (auto d : dd) {
		int ni = i + d.first;
		int nj = j + d.second;

		if (0 <= ni && ni < n && 0 <= nj && nj < m) {
			if (grid[ni][nj] <= grid[i][j]) {
				if (vis[ni][nj]) {
					dsu.union_sets(ni * m + nj, i * m + j);
				} else {
					dfs(grid, vis, dsu, ni, nj);
				}
			}
		}
	}
}

void solve() {
	// decreasing sequence in matrix leads to sink
	// for any decreasing sequence, there only needs to be one sink at the end

	int n, m;
	cin >> n >> m;

	vector<vector<int>> grid(n, vector<int>(m)), vis(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> grid[i][j];
	}

	DSU dsu(m*n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j]) dfs(grid, vis, dsu, i, j);
		}
	}

	int q;
	cin >> q;
	cout << dsu.get_sets() << "\n";
	int r, c, x;
	for (int i = 0; i < q; i++) {
		cin >> r >> c >> x;
		r--; c--;
		grid[r][c] -= x;
		for (auto d : dd) {
			int nr = r + d.first;
			int nc = c + d.second;
			if (0 <= nr && nr < n && 0 <= nc && nc < m) {
				if (grid[nr][nc] >= grid[r][c]) {
					dsu.union_sets(nr * m + nc, r * m + c);
				}
				if (grid[nr][nc] <= grid[r][c]) {
                     dsu.union_sets(nr * m + nc, r * m + c);
                }
			}
		}
		cout << dsu.get_sets() << "\n";
	}
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}