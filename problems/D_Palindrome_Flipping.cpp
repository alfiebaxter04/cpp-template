#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;

void apply_flip(string &s, int l, int r) {
    for (int k = l; k <= r; k++) {
        s[k] = (s[k] == '0' ? '1' : '0');
    }
}

vector<pair<int, int>> reduce(string s) {
    int n = s.size();
    vector<pair<int, int>> steps;

    for (int i = 0; i < n - 2; i++) {
        if (s[i] == '0') continue;

        if (s[i+1] == '1') {
            steps.push_back({i + 1, i + 2});
            apply_flip(s, i, i + 1);
        } else {
            if (s[i+2] == '1') {
                steps.push_back({i + 1, i + 3});
                apply_flip(s, i, i + 2);
            } else {
                steps.push_back({i + 2, i + 3});
                apply_flip(s, i + 1, i + 2);
                
                steps.push_back({i + 1, i + 3});
                apply_flip(s, i, i + 2);
            }
        }
    }
    
    if (s[n-2] == '1') {
        if (s[n-1] == '1') {
            steps.push_back({n-1, n});
            apply_flip(s, n-2, n-1);
        } else {
            steps.push_back({n-3, n-2}); 
            apply_flip(s, n-4, n-3);
            
            steps.push_back({n-3, n-1});
            apply_flip(s, n-4, n-2);
        }
    }

    if (s[n-1] == '1') {
        steps.push_back({n-3, n-1});
        apply_flip(s, n-4, n-2);
        
        steps.push_back({n-3, n});
        apply_flip(s, n-4, n-1);
    }
    
    for(char c : s) assert(c == '0');

    return steps;
}

void solve() {
	int n;
	string s, t;
	cin >> n >> s >> t;

	vector<pair<int, int>> p1 = reduce(s);
	vector<pair<int, int>> p2 = reduce(t);

	for (int i = p2.size()-1; i >= 0; i--) {
		p1.push_back(p2[i]);
	}

	assert(p1.size() <= 2*n);
	cout << p1.size() << "\n";
	for (auto [x, y] : p1) {
		cout << x << " " << y << "\n";
	}
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}