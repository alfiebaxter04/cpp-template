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

string output(int a, int b) {
    if (a == b) return "";
    if (b < a) swap(a, b);
    string s = to_string(a) + " " + to_string(b) + "\n";
    return s;
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    string s;
    cin >> s;

    bool bad = false;
    vector<int> mp(n+1);
    for (int i = 0; i < n; i++) {
        mp[p[i]] = i+1;
        if ((p[i] == 1 || p[i] == n) && s[i] == '1') bad = true;
    }
    if (s[0] == '1' || s[n-1] == '1' || bad) {
        cout << "-1\n";
        return;
    }

    // 1, 2, 3
    // 0, 1, 0

    unordered_set<string> out;
    out.insert(output(mp[1], mp[n]));
    out.insert(output(mp[1], 1));
    out.insert(output(mp[1], n));
    out.insert(output(mp[n], n));
    out.insert(output(mp[n], 1));
    out.erase("");

    cout << out.size() << "\n";
    for (string o : out) cout << o;
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}