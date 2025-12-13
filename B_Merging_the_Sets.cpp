#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;
using ll = long long;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;


void solve() {
    int n, m;
    cin >> n >> m;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> all(m+1, 0);
    vector<unordered_map<int, int>> sets;
    string s;
    int sz;
    for (int i = 0; i < n; i++) {
        cin >> sz;
        int tmp; unordered_map<int, int> st;
        while (sz--) {
            cin >> tmp;
            all[tmp]++; st[tmp]++;
        } 
        sets.push_back(st);
    }

    for (int i = 1; i <= m; i++) {
        if (all[i] == 0) {
            cout << "NO\n";
            return;
        }
    }

    int count = 1;
    for (int i = 0; i < sets.size(); i++) {
        bool flag = true;
        for (auto [x, f] : sets[i]) {
            if (all[x] - f <= 0) flag = false;
        }
        if (flag) count++;
    }
    if (count >= 3) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}