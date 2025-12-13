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
    int X, N;
    cin >> X >> N;
    vector<int> W(N);
    for (int i = 0; i < N; i++) cin >> W[i];
    vector<bool> set(N, false);

    int Q;
    cin >> Q;

    int P;
    for (int i = 0; i < Q; i++) {
        cin >> P;

        if (set[P-1]) {
            X -= W[P-1];
            set[P-1] = false;
        } else {
            X += W[P-1];
            set[P-1] = true;
        }

        cout << X << "\n";
    }
}

int main(){
	fastio;
    solve();
	return 0;
}