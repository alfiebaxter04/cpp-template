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
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;

    x = abs(x); y = abs(y);
    
    int op4 = 0, op8 = 0;
    for (char c : s) {
        if (c == '4') op4++;
        else op8++;
    }

    if (max(x, y) <= op8 + op4 && 2*op8 + op4 >= x + y) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}