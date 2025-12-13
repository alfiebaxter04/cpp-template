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
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> a;
    vector<int> b;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') a.push_back(i);
        if (s[i] == 'b') b.push_back(i);
    }

    if (a.size() == 0 || b.size() == 0) {
        cout << 0 << "\n";
        return;
    }

    int median_a = a[a.size()/2];
    ll ans_a = 0;

    for (int i = 0; i < a.size(); i++) {
        int target_a = median_a - a.size()/2 + i;
        ans_a += abs(target_a - a[i]);
    }
    
    int median_b = b[b.size()/2];
    ll ans_b = 0;

    for (int i = 0; i < b.size(); i++) {
        int target_b = median_b - b.size()/2 + i;
        ans_b += abs(target_b - b[i]);
    }

    cout << min(ans_a, ans_b) << "\n";

}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}