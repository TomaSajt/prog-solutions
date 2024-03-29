#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;

struct p {
    long long x, y;
};

vector<p> points;

inline bool online(int a, int b, int p) {
    return (points[b].x - points[a].x) * (points[p].y - points[a].y) == (points[p].x - points[a].x) * (points[b].y - points[a].y);
}
inline double dist2(int a, int b) {
    return (points[a].x - points[b].x) * (points[a].x - points[b].x) + (points[a].y - points[b].y) * (points[a].y - points[b].y);
}

int main() {
    speed;
    int n;
    cin >> n;
    points.resize(n);
    for (auto& p : points) cin >> p.x >> p.y;
    int b = 1;
    for (int i = 2; i < n; i++) {
        if (dist2(0, i) < dist2(0, b)) b = i;
    }
    double bestd = DBL_MAX;
    int c = -1;
    for (int i = 0;i < n;i++) {
        if (i == 0 || i == b || online(0, b, i)) continue;
        double currd = sqrt(dist2(0, i)) + sqrt(dist2(b, i));
        if (currd < bestd) {
            c = i;
            bestd = currd;
        }
    }
    cout << "1 " << b + 1 << ' ' << c + 1 << endl;
}


/*

#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;

struct point {
    long long x, y;
};

inline bool online(point a, point b, point p) {
    return (b.x - a.x) * (p.y - a.y) == (p.x - a.x) * (b.y - a.y);
}
inline double dist(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    speed;
    int n;
    cin >> n;
    vector<point> points(n);
    for (auto& p : points) cin >> p.x >> p.y;
    int a = 0, b = 1;;
    for (int i = 2;i < n;i++) {
        if (!online(points[a], points[b], points[i])) continue;
        if (dist(points[a], points[i]) < dist(points[a], points[b])) b = i;
    }
    double bestd = DBL_MAX;
    int c = -1;
    for (int i = 0;i < n;i++) {
        if (i == a || i == b || online(points[a], points[b], points[i])) continue;
        double currd = dist(points[a], points[i]) + dist(points[b], points[i]);
        if (currd < bestd) {
            c = i;
            bestd = currd;
        }
    }
    cout << a + 1 << " " << b + 1 << " " << c + 1 << endl;

}


*/