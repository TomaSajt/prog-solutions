typedef long long ll;

struct point {
    ll x, y;
};
struct pointd {
    double x, y;
};

inline ll turn(const point& a, const point& b, const point& c) {
    return (b.y - a.y) * (c.x - a.x) - (c.y - a.y) * (b.x - a.x);
}

inline pointd circumcenter(const pointd& a, const pointd& b, const pointd& c) {
    double am = a.x * a.x + a.y * a.y;
    double bm = b.x * b.x + b.y * b.y;
    double cm = c.x * c.x + c.y * c.y;
    double t = (b.x - a.x) * (c.y - b.y) - (b.x - c.x) * (a.y - b.y);
    double tx = (a.y - b.y) * cm + (b.y - c.y) * am + (c.y - a.y) * bm;
    double ty = (a.x - b.x) * cm + (b.x - c.x) * am + (c.x - a.x) * bm;
    return { 0.5 * tx / t, -0.5 * ty / t };
}