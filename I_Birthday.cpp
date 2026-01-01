#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "problems/debug.cpp"
#endif

using namespace std;
using ll = long long;
using ld = long double;

constexpr ld PI = 3.14159265358979323846;

struct Point {
    ll x, y;
    Point() {};
    Point(ll _x, ll _y) : x(_x), y(_y) {};
    bool operator<(const Point& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
	bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

ll cross_product(Point O, Point A, Point B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

ld dist_to_line(Point A, Point B) {
	// area of triangle OAB = 0.5 * |cross_product|
	ll cp = abs(cross_product(Point(0, 0), A, B));
	ld base = hypot(A.x - B.x, A.y - B.y);
	return cp / base;
}

ld segment_area(ld r, ld h) {
	if (h >= r) return 0.0;
	return r * r * acos(h / r) - h * sqrt(r * r - h * h);
}

vector<Point> convex_hull(vector<Point>& P) {
    int n = P.size(), k = 0;
    if (n <= 2) return P;
    vector<Point> H(2*n);
    sort(P.begin(), P.end());
    // build lower hull
    for (int i = 0; i < n; i++) {
        while (k >= 2 && cross_product(H[k-2], H[k-1], P[i]) <= 0) {
            k--;
        }
        H[k++] = P[i];
    }
    // build upper hull
    for (int i = n-2, t = k+1; i >= 0; i--) {
        while (k >= t && cross_product(H[k-2], H[k-1], P[i]) <= 0) {
            k--;
        }
        H[k++] = P[i];
    }
    H.resize(k-1);
    return H;
}

void solve() {
	int n, r;
	cin >> n >> r;
	vector<Point> p(n+1);
	p[0] = Point(0, 0);
	int x, y;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		p[i] = Point(x, y);
	}

	vector<Point> hull = convex_hull(p);

	cout << fixed << setprecision(10);

	// hull is outside the origin
	if (find(hull.begin(), hull.end(), Point(0, 0)) != hull.end()) {
		double half = 0.5 * PI * r * r;
		cout << half << "\n";
	} else {
		ld min_dist = r;
		int sz = hull.size();
		for (int i = 0; i < sz; i++) {
			Point p1 = hull[i];
			Point p2 = hull[(i+1) % sz];

			ld h = dist_to_line(p1, p2);
			min_dist = min(min_dist, h);
		}

		cout << segment_area(r, min_dist) << "\n";
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}