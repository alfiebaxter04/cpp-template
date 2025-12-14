#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;
using ll = long long;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;



int main(){
	fastio;
    int n;
    cin >> n;

    // n = 6 -> 1, 3, 5, 2, 4, 6
    // n = 4 -> 1, 3, 2,
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION" << "\n";
        return 0;
    }

    if (n == 4) {
        cout << "2 4 1 3" << "\n";
        return 0;
    }

    for (int i=1; i<=n; i+=2) {
        cout << i << " ";
    }

    for (int i=2; i<=n; i+=2) {
        cout << i << " ";
    }

    cout << "\n";
}