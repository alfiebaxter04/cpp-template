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

const int INF = 1e9;

void solve() {
	int n;
	cin >> n;
	
	vector<int> r1(n), r2(n);
	for (int i = 0; i < n; i++) cin >> r1[i];
	for (int i = 0; i < n; i++) cin >> r2[i];
	vector<vector<int>> grid { r1, r2 };
	// min/max for prefix of r1
	// min/max for suffix of r2

	vector<int> Pmin(n, INF), Pmax(n, -INF);
	vector<int> Smin(n, INF), Smax(n, -INF);
	Pmin[0] = Pmax[0] = grid[0][0];
	Smin[n-1] = Smax[n-1] = grid[1][n-1];

	for (int i = 1; i < n; i++) {
		Pmin[i] = min(Pmin[i-1], grid[0][i]);
		Pmax[i] = max(Pmax[i-1], grid[0][i]);
	}

	for (int i = n-2; i >= 0; i--) {
		Smin[i] = min(Smin[i+1], grid[1][i]);
		Smax[i] = max(Smax[i+1], grid[1][i]);
	}

	int L = -INF, R = INF;
	vector<pair<int, int>> pairs;
	for (int i = 0; i < n; i++) {
		L = min(Pmin[i], Smin[i]);
		R = max(Pmax[i], Smax[i]);
		pairs.push_back({L, R});
	}
    sort(pairs.begin(), pairs.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        return a.first > b.first;
    });

    ll ans = 0;
    int min_v_so_far = INF; 
    int prev_u = pairs[0].first; 

    for (auto &p : pairs) {
        int u = p.first;
        int v = p.second;

        if (u < prev_u) {
			ll count_l = prev_u - u;
			ll count_r = 2 * n - min_v_so_far + 1;
			ans += count_l * count_r;
            prev_u = u;
        }

        min_v_so_far = min(min_v_so_far, v);
    }

	ll count_l = prev_u;
	ll count_r = 2 * n - min_v_so_far + 1;
	ans += count_l * count_r;

    cout << ans << "\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}