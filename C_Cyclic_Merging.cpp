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
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;	

	set<pair<int, int>> list;
	vector<pair<int, int>> sa;
	for (int i = 0; i < n; i++) list.insert({i, a[i]});
	for (int i = 0; i < n; i++) sa.push_back({a[i], i});
	sort(sa.begin(), sa.end());

	ll cost = 0;
	for (int i = 0; i < n - 1; i++) {
		auto [val, idx] = sa[i];
		auto it = list.lower_bound({idx, val});
		auto left = it;
		if (it == list.begin()) left = list.end();
		left--;

		auto right = it; right++;
		if (right == list.end()) right = list.begin();

		cost += min(left->second, right->second);
		list.erase(it);
	}

	cout << cost << "\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}