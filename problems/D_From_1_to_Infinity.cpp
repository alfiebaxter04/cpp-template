#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "debug.cpp"
#endif

using namespace std;
using ll = long long;

ll f(ll n) {
    if (n <= 0) return 0;
    string s = to_string(n);
    int first = s[0]-'0';

    // length of number
    ll sz = 1, p10 = 1;
    while (p10 * 10 <= n) {
        sz++; p10 *= 10;
    }

    ll b = 45 * (sz-1) * (p10/10);
    ll out = first * b;
    for (int i = 0; i < first; i++) {
        out += i * p10;
    }

    out += first * (n - (p10 * first) + 1);

    return out + f(n%p10);
}

void solve() {
    ll k; cin >> k;
    // sum of digits 1..N
    // find N first and add offset

    ll sum = 0;
    ll d = 0, p = 1, t = 1;
    while (d + 9*t*p < k) {
        d += 9 * t * p;
        p++; t *= 10; 
    }
    ll left = k - d;
    ll bonus = left / p;
    ll N = t + bonus - 1;

    string s = to_string(N+1);
    for (int i = 0; i < left % p; i++) {
        sum += s[i]-'0';
    }

    cout << sum + f(N) << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
	    solve();
}