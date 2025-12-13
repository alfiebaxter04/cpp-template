#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;
using ll = long long;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;


void solve() {
    ll n, cur, res;
    cin >> n;

    vector<int> d;
    for (int i=0; i<n; i++) {
        cin >> cur; 

        if (cur % 2 == 0) {
            res += cur;     
        } else {
            d.push_back(cur);
        }
    }

    std::sort(d.begin(), d.end());
    for (int i=d.size()/2; i < d.size(); i++) {
        res += d[i];
    }

    cout << res << "\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}