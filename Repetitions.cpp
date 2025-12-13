#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;
using ll = long long;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;


void solve() {
	
}

int main(){
    string s;
    cin >> s;

    int max = 1;
    int cur = 1;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i-1]) {
            cur = 1;
        } else {
            cur += 1;
        }

        max = std::max(max, cur);
    }

    cout << max << "\n";
    
}