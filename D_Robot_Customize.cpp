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
    int N;
    cin >> N;
    vector<int> W(N), H(N), B(N);
    int totalW = 0;
    for (int i = 0; i < N; i++) {
        cin >> W[i] >> H[i] >> B[i];
        totalW += W[i];
    }

    ll happy = 0;
    int head = 0, body = 0;

    // dp[i][w] = max happiness with first i rows with head weight <= w
    vector<vector<ll>> dp(N, vector<ll>(totalW/2 + 1, 0));
    for (int w = 0; w <= totalW/2; w++) {
        dp[0][w] = B[0];
        if (w >= W[0]) dp[0][w] = max(dp[0][w], (ll)H[0]);
    }

    for (int i = 1; i < N; i++) {
        for (int w = 0; w <= totalW/2; w++) {
            dp[i][w] = dp[i-1][w] + B[i];
            if (W[i] <= totalW/2 && w-W[i] >= 0)
                dp[i][w] = max(dp[i][w], dp[i-1][w-W[i]]+H[i]);
        }
    }

    cout << dp[N-1][totalW/2] << "\n";
}

int main(){
	fastio;
    solve();
	return 0;
}