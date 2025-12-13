#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;
using ll = long long;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

int main(){
	fastio;
	ll n;
	cin >> n;

    ll t1 = n * (n+1) / 2;
    ll t2 = 0;
    ll num;
    for (int i=0; i<n-1; i++) {
       cin >> num;
       t2 += num; 
    }

    cout << t1 - t2 << "\n";
}