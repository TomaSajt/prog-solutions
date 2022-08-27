#include <bits/stdc++.h>
#define PI 3.141592653589
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;

struct point {
    double x, y;
};

inline double angle(const point& o, const point& a, const point& b) {
    double res = atan2(b.y - o.y, b.x - o.x) - atan2(a.y - o.y, a.x - o.x);
    return res < 0 ? res + 2 * PI : res;
}

inline double mag2(const point& a) {
    return a.x * a.x + a.y * a.y;
}

inline point circumcenter(const point& a, const point& b, const point& c) {
    double am = mag2(a), bm = mag2(b), cm = mag2(c);
    double turn = (b.x - a.x) * (c.y - b.y) - (b.x - c.x) * (a.y - b.y);
    double tx = (a.y - b.y) * cm + (b.y - c.y) * am + (c.y - a.y) * bm;
    double ty = (a.x - b.x) * cm + (b.x - c.x) * am + (c.x - a.x) * bm;
    return { 0.5 * tx / turn, -0.5 * ty / turn };
}


int main() {
    point a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    point o = circumcenter(a, b, c);
    double r = sqrt(mag2({ a.x - o.x,a.y - o.y }));
    double u = angle(o, a, b) / PI / 2, v = angle(o, a, c) / PI / 2;
    for (int i = 3; i <= 100; i++) {
        double ui = u * i, vi = v * i;
        if (abs(ui - round(ui)) < 0.001 && abs(vi - round(vi)) < 0.001) {
            cout << setprecision(7) << 0.5 * i * r * r * sin(2 * PI / i);
            return 0;
        }
    }
}