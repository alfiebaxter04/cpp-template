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


void solve() {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    int n = s.size();
    int any = 0;

    vector<char> ans(n);
    for (int i = 0; i < n; i++) ans[i] = s[i];

    for (int i = 0; i < n; i++) {
        if (ans[i] != '?') {
            if (s[n-i-1] == '?') {
                ans[n-i-1] = ans[i]; 
            }
        } 
    }

    unordered_map<char, int> freq;
    for (auto c : ans) freq[c]++;
    if (n % 2 == 1 && ans[n/2] == '?') {
        if ((a - freq['0']) % 2 == 1) {
            ans[n/2] = '0';
            freq['0']++;
        } else {
            ans[n/2] = '1';
            freq['1']++;
        }
    }

    for (int i = 0; i < n; i++) {
        char c = ans[i];

        if (c == '?') {
            if (a - freq['0'] <= b - freq['1']) {
                ans[i] = '1';
                ans[n-i-1] = '1';
                freq['1'] += 2;
            } else {
                ans[i] = '0';
                ans[n-i-1] = '0';
                freq['0'] += 2;
            }
            freq['?'] -= 2;
        }
    }

    if (freq['?'] != 0 || freq['0'] != a || freq['1'] != b) {
        cout << -1 << "\n";
    } else {
        for (auto c : ans) cout << c;
        cout << "\n";
    }
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}