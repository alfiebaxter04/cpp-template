#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;

struct chash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
	int n;
	cin >> n;
	vector<int> a(2*n);
	for (int i = 0; i < 2*n; i++) cin >> a[i];
	
	unordered_map<int, int, chash> freq;
	for (int num : a) freq[num]++;

	// even frequency -> can put odd count in each
	// odd frequency  -> can only put odd in one
	// we can partition like this so that at max differences in sizes is 1.
	// for each odd, one side will get even frequency
	// if no odd, then parity of n must be same as even count
	// n = 5, 5 even freqs -> each side has 5 odd -> sum is odd
	// n = 6, 5 even freqs -> each side has 5 odd -> sum is odd -> need to use one frequency to balance
	// n = 4, 3 even freqs
	// 1, 1, 1, 1, 2, 2, 3, 3
	// 1, 1, 1 - 1
	// 1, 1, 1 - 1, 2
	// 1, 1, 1, 2, 3 - 1, 2, 3

	// n = 3, 3 even freqs
	// 1, 1, 1, 1, 2, 3
	// 1, 1, 1 - 1,
	// 1, 1, 1, - 1, 2, 3	

	// COUNT OF ODD FREQS ALWAYS EVEN
	// So we don't have to worry about balancing odds
	// can use odds to counteract fuck ups in balance
	
	// if we do smart greedy allocation,  max diff in set sizes -> 2

	int odd = 0, even = 0;
	for (auto [v, num] : freq) {
		if (num % 2) odd++;
		else even++;
	}
	int ans = 2*even + odd;
	if (!odd && n % 2 != even % 2) ans -= 2;

	cout << ans << "\n";
}

int main(){
	fastio;
	int t;
	cin >> t;
	
	while (t--) solve();
	return 0;
}