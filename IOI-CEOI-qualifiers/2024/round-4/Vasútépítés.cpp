#include <bits/stdc++.h>
#define int long long
using namespace std;

int big = 1e9;
int t = 1;

vector<vector<int>> p;
vector<vector<int>> g;
vector<vector<int>> comps;
vector<int> vis;
int vis_mark = 1;

void dfs1(int u) {
  vis[u] = vis_mark;
  comps.back().push_back(u);
  for (int v : g[u]) {
    if (vis[v] == vis_mark) continue;
    dfs1(v);
  }
}

stack<int> s;
bool find_cycle(int u, int par) {
  s.push(u);
  vis[u] = vis_mark;
  for (int v : g[u]) {
    if (v == par) continue;
    if (vis[v] == vis_mark) {
      s.push(v);
      return true;
    }
    if (find_cycle(v, u)) return true;
  }
  s.pop();
  return false;
}

void dfs2(int u) {
  vis[u] = vis_mark;
  for (int v : g[u]) {
    if (vis[v] == vis_mark) continue;
    p[u][v] = p[v][u] = t++;
    dfs2(v);
  }
}

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m;
  cin >> n >> m;
  p.resize(n + 1, vector<int>(n + 1, -1));
  g.resize(n + 1);
  vis.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    if (vis[i] == vis_mark) continue;
    comps.emplace_back();
    dfs1(i);
  }

  for (vector<int> comp : comps) {
    int edge_cnt = 0;
    for (int u : comp) {
      for (int v : g[u]) {
        if (u < v) edge_cnt++;
      }
    }

    if (comp.size() == 1 || edge_cnt > comp.size()) {
      cout << "-1";
      return 0;
    }
    if (edge_cnt == comp.size()) {
      s = stack<int>();
      vis_mark++;
      assert(find_cycle(comp[0], -1));
      vis_mark++;

      int start = s.top();
      s.pop();
      int curr = start;
      int cycle_mark = vis_mark;
      do {
        vis[curr] = vis_mark;
        p[curr][s.top()] = p[s.top()][curr] = t++;
        curr = s.top();
        s.pop();
      } while (curr != start);
      vis_mark++;
      for (int i : comp) {
        if (vis[i] == cycle_mark) dfs2(i);
      }
    }
    if (edge_cnt < comp.size()) {
      vis_mark++;
      dfs2(comp[0]);
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (p[i][j] == -1) {
        cout << big-- << ' ';
      }
      else {
        cout << p[i][j] << ' ';
      }
    }
    cout << '\n';
  }
}
