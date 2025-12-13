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
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> head(N), body(M);
    for (int i = 0; i < N; i++) cin >> head[i];
    for (int i = 0; i < M; i++) cin >> body[i];
    // head <= body, k times

    sort(head.begin(), head.end());
    sort(body.begin(), body.end());

    auto it = lower_bound(head.begin(), head.end(), body.back());
    int ph = it - head.begin();
    ph = min(N-1, ph);
    int pb = M-1;

    while (ph >= 0 && pb >= 0) {
        if (head[ph] <= body[pb]) {
            K--; ph--; pb--;
        } else {
            ph--;
        }
    }

    if (K <= 0) cout << "Yes" << "\n";
    else cout << "No" << "\n";
}

int main(){
	fastio;
    solve();
	return 0;
}