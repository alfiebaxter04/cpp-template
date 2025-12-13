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

    ll t_sum = (n * (n + 1)) / 2;
    if (t_sum % 2 != 0) {
        cout << "NO" << "\n";
        return 0;
    }

    vector<int> s1, s2;
    if (n % 2 == 0) {
        for (int i = 1; i < n; i += 4) {
            s1.push_back(i);
            s1.push_back(i + 3);
            s2.push_back(i + 1);
            s2.push_back(i + 2);
        }
    } else {
        s1.push_back(1);
        s1.push_back(2);
        s2.push_back(3);
        for (int i = 4; i < n; i += 4) {
            s1.push_back(i);
            s1.push_back(i + 3);
            s2.push_back(i + 1);
            s2.push_back(i + 2);
        }
    }

    cout << "YES" << "\n";
    cout << s1.size() << "\n";
    for (int num : s1) {
        cout << num << " ";
    }
    cout << "\n" << s2.size() << "\n";
    for (int num : s2) {
        cout << num << " ";
    }
    cout << "\n";
}