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
    string s;
    cin >> s;

    unordered_map<char, int> freq;

    // at most one char of odd count, rest even

    for (char c : s) freq[c]++;

    int odd = 0;
    char odd_char;
    vector<char> st;
    string ans = "";
    for (auto &p : freq) {
        if (p.second % 2 == 1) {
            odd++;
            odd_char = p.first;
        } else {
            ans.insert(ans.end(), freq[p.first]/2, p.first);
            st.push_back(p.first);
        }
        
    }

    if (odd > 1) {
        cout << "NO SOLUTION" << "\n";
        return;
    }

    if (odd_char) {
        ans.insert(ans.end(), freq[odd_char], odd_char);
    }

    while (!st.empty()) {
        char c = st.back();
        st.pop_back();
        ans.insert(ans.end(), freq[c]/2, c);
    }

    cout << ans << "\n";
}

int main(){
	fastio;
    solve();
}