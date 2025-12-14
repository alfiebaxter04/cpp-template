#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;
using ll = long long;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> freq;
    for (int num : a) {
        freq[num]++;
    }

    map<int, int> freqs;
    int tot = 0;
    for (auto [x, f] : freq) {
        freqs[f]++;
        tot++;
    }

    int ans = 0;
    for (auto [x, f] : freqs) {
        ans = max(ans, x*tot);
        tot -= f;
    }

    cout << ans << "\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}