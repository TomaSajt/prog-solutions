#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct point {
  ll x, y;
};

ll turn(const point &a, const point &b, const point &c) {
  return (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x);
}

int n;
vector<point> points;

bool possible(int i, int j) {
  set<ll> uniq;
  for (int k = 0; k < n; k++) {
    uniq.insert(turn(points[i], points[j], points[k]));
    if (uniq.size() > 2)
      return false;
  }
  return uniq.size() == 2;
}

int main() {
  cin >> n;
  points.resize(n);
  for (int i = 0; i < n; i++) {
    points[i].x = i;
    cin >> points[i].y;
  }
  cout << (possible(0, 1) || possible(0, 2) || possible(1, 2) ? "Yes" : "No");
}
