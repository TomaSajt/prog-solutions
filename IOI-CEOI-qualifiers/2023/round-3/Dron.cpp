// 30/100
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct point {
  int x, y;
};

struct edge {
  int u, v;
};

int n;
vector<point> pts;

int dist(int i, int j) {
  return abs(pts[i].x - pts[j].x) + abs(pts[i].y - pts[j].y);
}

vector<int> parent;
vector<int> depth;

int get_parent(int u) {
  if (parent[u] == u) {
    return u;
  }
  return parent[u] = get_parent(parent[u]);
}

void merge(int u, int v) {
  u = get_parent(u);
  v = get_parent(v);
  if (u == v)
    cout << 1 / 0;
  if (depth[u] < depth[v]) {
    swap(u, v);
  }
  if (depth[u] == depth[v]) {
    depth[u]++;
  }
  parent[v] = u;
}

signed main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  pts.resize(n);
  parent.resize(n);
  depth.resize(n, 1);
  iota(parent.begin(), parent.end(), 0);

  for (auto &p : pts) {
    cin >> p.x >> p.y;
  }

  vector<edge> edges;

  for (int i = 0; i < n; i++) {
    int tj = -1, bj = -1, rj = -1, lj = -1;
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }
      int x = pts[j].x - pts[i].x;
      int y = pts[j].y - pts[i].y;
      if (y > abs(x)) {
        if (tj == -1 || dist(i, j) < dist(i, tj)) {
          tj = j;
        }
      } else if (y < -abs(x)) {
        if (bj == -1 || dist(i, j) < dist(i, bj)) {
          bj = j;
        }
      } else if (x >= abs(y)) {
        if (rj == -1 || dist(i, j) < dist(i, rj)) {
          rj = j;
        }
      } else if (x <= -abs(y)) {
        if (lj == -1 || dist(i, j) < dist(i, lj)) {
          lj = j;
        }
      }
    }
    if (tj != -1) {
      edges.push_back({i, tj});
    }
    if (bj != -1) {
      edges.push_back({i, bj});
    }
    if (rj != -1) {
      edges.push_back({i, rj});
    }
    if (lj != -1) {
      edges.push_back({i, lj});
    }
  }
  sort(edges.begin(), edges.end(),
       [&](edge e1, edge e2) { return dist(e1.u, e1.v) < dist(e2.u, e2.v); });

  int cnt = n;
  for (auto &[u, v] : edges) {
    if (get_parent(u) != get_parent(v)) {
      merge(u, v);
      cnt--;
      if (cnt == 1) {
        cout << dist(u, v);
        return 0;
      }
    }
  }

  return 0;
}
