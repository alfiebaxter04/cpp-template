#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;
using ll = long long;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

int main(){
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i=0; i<n; i++) {
        cin >> nums[i];
    }

    ll total = 0;
    for (int i=1; i<n; i++) {
        if (nums[i] < nums[i-1]) {
            total += nums[i-1] - nums[i];
            nums[i] = nums[i-1];
        }
    }

    cout << total << "\n";
}