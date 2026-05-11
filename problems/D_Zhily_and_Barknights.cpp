#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
#define int long long

const int MOD = 998244353;
const int INF = 2e9;

int pow(int a, int b, int m){
    int ans = 1;
    while(b){
        if (b&1) ans = (ans*a) % m;
        b /= 2;
        a = (a*a) % m;
    }
    return ans;
}

struct Frac {
	int top, bot;
	bool operator<(const Frac& o) const {
		return top * o.bot < o.top * bot;
	}
	Frac(int t, int b) : top(t), bot(b) {}
};

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int& x : a) cin >> x;
	for (int& x : b) cin >> x;

	vector<Frac> D; D.reserve(n*n);
	vector<Frac> P; P.reserve(n*n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j)
				P.push_back(Frac(b[j],b[i]));
			if (j > i)
				D.push_back(Frac(a[i], a[j]));
		}
	}
	
	sort(D.begin(), D.end());
	sort(P.begin(), P.end());

	int r = 0, invs = 0;
	for (int l = 0; l < D.size(); l++) {
		while (r < P.size() && P[r] < D[l]) r++;
		invs += r;
		if (invs >= MOD) invs -= MOD;
	}

	int p = invs, q = n*(n-1);
	cout << ((p % MOD) * pow(q, MOD-2, MOD) % MOD) << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
}