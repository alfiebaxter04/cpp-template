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

vector<int> get_primes(int n) {
    vector<bool> is(n+1, true);
    is[0] = false; is[1] = false;

    for (int i = 2; i <= n; i++) {
        if (is[i]) {
            for (int j = i+i; j <= n; j += i)
                is[j] = false;
        }
    }

    vector<int> out;
    for (int i = 2; i <= n; i++)
        if (is[i]) out.push_back(i);

    return out;
}

vector<int> primes = get_primes(100000);

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];


    for (int p : primes) {
        for (ll t : a) {
            if (t % p != 0) {
                cout << p << "\n";
                return;
            }
        }
    }

    cout << -1 << "\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}