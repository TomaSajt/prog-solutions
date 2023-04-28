// doesn't work, because of concave shapes 0/100
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct point {
  int x, y;
};

int len2(const point &p) { return p.x * p.x + p.y * p.y; }

int dist2(const point &a, const point &b) {
  return len2({a.x - b.x, a.y - b.y});
}

int dot(const point &a, const point &b) { return a.x * b.x + a.y * b.y; }

int turn(const point &a, const point &b, const point &c) {
  return (c.x - a.x) * (c.y - b.y) - (c.y - a.y) * (c.x - b.x);
}

int turns(const point &a, const point &b, const point &c) {
  int r = turn(a, b, c);
  return (r > 0) - (r < 0);
}

bool inside_triangle(const point &a, const point &b, const point &c,
                     const point &p) {
  int s = turns(a, b, p);
  return s == turns(b, c, p) && s == turns(c, a, p);
}

void dfs_bridges(const vector<vector<int>> &g, set<pair<int, int>> &br,
                 vector<int> &d, vector<int> &l, int &t, int u, int p) {
  d[u] = l[u] = ++t;
  for (auto &v : g[u]) {
    if (v == p) {
      continue;
    }
    if (d[v]) {
      l[u] = min(l[u], d[v]);
    } else {
      dfs_bridges(g, br, d, l, t, v, u);
      l[u] = min(l[u], l[v]);
      if (d[u] < l[v]) {
        br.insert(minmax(u, v));
      }
    }
  }
}

set<pair<int, int>> get_bridges(const vector<vector<int>> &g) {
  int n = g.size();
  int t = 0;
  set<pair<int, int>> br;
  vector<int> d(n), l(n);
  for (int i = 0; i < n; i++) {
    if (d[i] != 0) {
      continue;
    }
    dfs_bridges(g, br, d, l, t, i, -1);
  }
  return br;
}

void dfs_explore(const vector<vector<int>> &g, set<pair<int, int>> &br,
                 vector<int> &group, vector<bool> &vis, int u) {
  if (vis[u]) {
    return;
  }
  vis[u] = true;
  group.push_back(u);
  for (auto &v : g[u]) {
    if (br.count(minmax(u, v))) {
      continue;
    }
    dfs_explore(g, br, group, vis, v);
  }
}

vector<vector<int>> make_groups(const vector<vector<int>> &g,
                                set<pair<int, int>> &br) {
  int n = g.size();
  vector<bool> vis(n);
  vector<vector<int>> groups;
  for (int i = 0; i < n; i++) {
    if (vis[i]) {
      continue;
    }
    groups.emplace_back();
    dfs_explore(g, br, groups.back(), vis, i);
  }
  return groups;
}

signed main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<point> pts(n);
  for (auto &p : pts) {
    cin >> p.x >> p.y;
  }

  vector<vector<int>> others(n);
  for (int i = 0; i < n; i++) {
    others[i].reserve(n - 1);
    for (int j = 0; j < n; j++) {
      if (i != j) {
        others[i].push_back(j);
      }
    }
    sort(others[i].begin(), others[i].end(), [&](int j1, int j2) {
      return dist2(pts[i], pts[j1]) < dist2(pts[i], pts[j2]);
    });
  }

  cout << -1;
  return 0;

  auto check = [&](int max_dist2) {
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++) {
      for (int j : others[i]) {
        if (dist2(pts[i], pts[j]) > max_dist2) {
          break;
        }
        graph[i].push_back(j);
      }
    }

    auto bridges = get_bridges(graph);
    auto groups = make_groups(graph, bridges);

    auto check_group = [&](const vector<int> group) {
      int i = group[0];
      int j1 = -1, j2 = -1;
      for (auto &j : group) {
        if (j == i)
          continue;
        if (turn({0, 0}, pts[i], pts[j]) > 0) {
          if (j1 == -1) {
            j1 = j;
            continue;
          }
          int a = dot(pts[i], pts[j1]);
          int b = dot(pts[i], pts[j]);
          if (b < a) {
            j1 = j;
          }
        } else {
          if (j2 == -1) {
            j2 = j;
            continue;
          }
          int a = dot(pts[i], pts[j2]);
          int b = dot(pts[i], pts[j]);
          if (b < a) {
            j2 = j;
          }
        }
      }

      if (j1 == -1 || j2 == -1) {
        return false;
      }

      return inside_triangle(pts[i], pts[j1], pts[j2], {0, 0});
    };

    for (auto &group : groups) {
      if (check_group(group)) {
        return true;
      }
    }
    return false;
  };

  if (!check(LLONG_MAX)) {
    cout << -1;
    return 0;
  }

  int curr = 0;
  for (int i = 62; i >= 0; i--) {
    int next = curr + (1ll << i);
    if (!check(next)) {
      curr = next;
    }
  }

  cout << curr + 1;

  return 0;
}
