// refactored from mraron's code

#include <bits/stdc++.h>
using namespace std;
const int BIG = 1e9;

vector<vector<array<int, 3>>> g;
vector<int> l, d, comp_id, tom_dist, hole_dist;
int hole, ts = 0, curr_comp_id = 1;
stack<int> st;

// components are separated by cutting vertices
void make_comps(int u, int par_ei) {
  d[u] = l[u] = ++ts;
  int ch = 0;
  for (auto& [v, w, ei] : g[u]) {
    if (par_ei == ei) continue;  // case: tree-edge, from the other direction
    if (d[v] > d[u]) continue;   // case: back-edge, from the other direction
    st.push(ei);
    if (d[v] != 0) {
      // case: (u,v) is back-edge
      l[u] = min(l[u], d[v]);
      continue;
    }
    // case: (u,v) is tree-edge
    ch++;
    make_comps(v, ei);
    l[u] = min(l[u], l[v]);

    if ((ch > 1 && par_ei == -1) || (l[v] >= d[u])) {
      // case: u is a cutting vertex
      while (st.top() != ei) {
        comp_id[st.top()] = curr_comp_id;
        st.pop();
      }
      comp_id[st.top()] = curr_comp_id++;
      st.pop();
    }
  }
}

vector<bool> vis;

// last_safe: for how many timesteps can tom move until we have to leave the current space
vector<int> last_safe, best_tom_start;

void calc_safe(int u, int par_ei_comp) {
  vis[u] = 1;

  for (auto& [v, w, ei] : g[u]) {
    if (vis[v]) continue;
    if (hole_dist[v] != hole_dist[u] + 1) continue;  // case: not going the shortest way
    if (comp_id[ei] == par_ei_comp) {
      // case: inside component
      last_safe[v] = last_safe[u] - 1;
      best_tom_start[v] = best_tom_start[u];
    }
    else {
      // case: changing components, u is cutting vertex
      if (tom_dist[u] <= last_safe[u]) {
        last_safe[v] = tom_dist[u] - 1;
        best_tom_start[v] = u;
      }
      else {
        last_safe[v] = last_safe[u] - 1;
        best_tom_start[v] = best_tom_start[u];
      }
    }
    calc_safe(v, comp_id[ei]);
  }
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);

  int n, m, tom, j_cnt;
  cin >> n >> m >> tom >> j_cnt >> hole;

  g.resize(n + 1);
  for (int ei = 0; ei < m; ei++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w, ei});
    g[v].push_back({u, w, ei});
  }

  l.resize(n + 1), d.resize(n + 1), comp_id.resize(m + 1);
  make_comps(hole, -1);
  while (!st.empty()) {
    comp_id[st.top()] = curr_comp_id;
    st.pop();
  }
  curr_comp_id++;

  queue<int> q;
  q.push(tom);
  tom_dist.assign(n + 1, BIG);
  tom_dist[tom] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto& [v, w, ei] : g[u]) {
      if (w != 2 || tom_dist[v] != BIG || v == hole) continue;
      tom_dist[v] = tom_dist[u] + 1;
      q.push(v);
    }
  }

  q.push(hole);
  hole_dist.assign(n + 1, BIG);
  hole_dist[hole] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto& [v, w, ei] : g[u]) {
      if (hole_dist[v] != BIG) continue;
      hole_dist[v] = hole_dist[u] + 1;
      q.push(v);
    }
  }

  vis.resize(n + 1, 0);
  last_safe.resize(n + 1, BIG);
  best_tom_start.resize(n + 1, -1);
  calc_safe(hole, -1);

  while (j_cnt--) {
    int u;
    cin >> u;
    cout << (last_safe[u] > 0 ? 0 : best_tom_start[u]) << '\n';
  }
}
