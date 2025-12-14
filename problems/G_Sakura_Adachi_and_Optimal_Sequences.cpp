#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;

const int MOD = 1e6 + 3;
const int INF = 1e7;
vector<ll> powers, fact;

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

void work(int N) {
    int p = 1;
    while (p <= INF) {
        powers.push_back(p);
        p *= 2;
    }

    fact.assign(N+1, 0);
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
}

ll get_fact(long long x) {
    if (x > MOD) return 0;
    return fact[x];
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    

    int d_ops = INF;
    vector<int> req(n, 0);
    for (int i = 0; i < n; i++) {
        int p_idx = upper_bound(powers.begin(), powers.end(), b[i]/a[i]) - powers.begin() - 1;
        d_ops = min(d_ops, p_idx);
    }

    ll X = 0;
    vector<int> stages, at_op(d_ops, 0);
    for (int i = 0; i < n; i++) {
        int ops = d_ops;
        int now = b[i], end = a[i];
        while (ops && now >= 2*end) {
            if (now % 2) {
                now -= 1;
                req[i]++;
                at_op[ops-1]++;
            }
            now /= 2; ops--;
        }
        stages.push_back(now - end);
        req[i] += now - end;
        X += req[i];
    }

    // ops are sum(req) + d_ops
    ll demon = 1, sum = 0;
    for (int s : stages) {
        sum += s;
        demon = (demon * get_fact(s)) % MOD;
    }

    ll inv = modpow(demon, MOD - 2);
    ll out = (get_fact(sum) * inv) % MOD;
    for (int at : at_op) {
        if (at) out = (out * get_fact(at)) % MOD;
    }

    cout << X + d_ops << " " << out << "\n";
}

int main(){
	fastio;
	int t;
	cin >> t;

    work(MOD+5);
	
	while (t--) solve();
	return 0;
}