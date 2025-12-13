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
    int H, W;
    cin >> H >> W;

    vector<string> M(H);
    for (int i = 0; i < H; i++) cin >> M[i];

    // dp[i][j][0] = min cost to point down from (i, j)
    // dp[i][j][1] = min cost to point right from (i, j)
    int dp[H][W][2];
    memset(dp, 0x3f, sizeof(dp));

    if      (M[0][0] == 'A') { dp[0][0][1] = 0; dp[0][0][0] = 1; }
    else if (M[0][0] == 'B') { dp[0][0][1] = 1; dp[0][0][0] = 0; }
    else if (M[0][0] == 'C') { dp[0][0][1] = 1; dp[0][0][0] = 1; }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 && j == 0) continue;
            if (i > 0) {
                // can look above
                if (M[i][j] == 'A') {
                    dp[i][j][0] = dp[i-1][j][0];
                    dp[i][j][1] = dp[i-1][j][0]+1;
                } else if (M[i][j] == 'B') {
                    dp[i][j][0] = dp[i-1][j][0]+1;
                    dp[i][j][1] = dp[i-1][j][0];
                } else if (M[i][j] == 'C') {
                    dp[i][j][0] = dp[i-1][j][0]+1;
                    dp[i][j][1] = dp[i-1][j][0]+1;
                }
            }
            if (j > 0) {
                // can look left
                if (M[i][j] == 'A') {
                    dp[i][j][0] = min(dp[i][j][0], dp[i][j-1][1]+1);
                    dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][1]);
                } else if (M[i][j] == 'B') {
                    dp[i][j][0] = min(dp[i][j][0], dp[i][j-1][1]+1);
                    dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][1]);
                } else if (M[i][j] == 'C') {
                    dp[i][j][0] = min(dp[i][j][0], dp[i][j-1][1]+1);
                    dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][1]+1);
                }
            }
        }
    }

    cout << dp[W-1][H-1][1] << "\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}