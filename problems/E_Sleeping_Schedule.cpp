#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;
using ll = long long;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

int main(){
	fastio;

    int n, h, l, r;
    cin >> n >> h >> l >> r;

    int solve(int day, int time) {
        if (day > n) {
            return 0;
        }

        int best = 0;

        int nt1 = (time + a[day]) % h;
        int ig1 = (l <= nt1 <= r) ? 1 : 0;
        best = max(best, ig1 + solve(day+1, nt1));

        int nt2 = (time + a[day] - 1 + h) % h;
        int ig2 = (l <= nt2 <= r) ? 1 : 0;

        best = max(best, ig2 + solve(day+1, nt2));

        return best
    }

    int best = solve(0, 0);
    cout << best << "\n";
}