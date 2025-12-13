#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
template <class T> void _print(const vector<T> &v) {cerr<<"[ ";for(auto& i:v)cerr<<i<<" ";cerr<<"] ";}

void solve() {
	string s, t;
	cin >> s >> t;
	
	vector<int> fs(26, 0), ft(26, 0);
	for (char c : s) fs[c-'a']++;
	for (char c : t) ft[c-'a']++;

	bool flag = true;
	for (int i = 0; i < 26; i++) {
		if (fs[i] > ft[i]) flag = false;
	}

	if (!flag) {
		cout << "Impossible\n";
		return;
	}


	string ans = "";
	int sp = 0;
	// first char = 's', place all characters befores leaving enough for rest of string
	while (sp < s.size()) {
		for (int i = 0; i < (int)s[sp]-'a'; i++) {
			int times = ft[i] - fs[i];
			for (int j = 0; j < times; j++) {
				ans += char(i+'a');
				ft[i]--;
			}
		}
		ans += s[sp];
		int idx = s[sp]-'a';
		fs[idx]--;
		ft[idx]--;
		sp++;
	}
	for (int i = 0; i < 26; i++) {
		while (ft[i] > 0) {
			ans += char('a'+i);
			ft[i]--;
		}
	}
	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}