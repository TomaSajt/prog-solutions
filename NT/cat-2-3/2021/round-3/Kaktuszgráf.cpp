#include <bits/stdc++.h>
using namespace std;

vector<vector<array<int, 2>>> g;
vector<int> l, d;
int ts = 0;
stack<int> st;
vector<int> comp_sizes;

// components are separated by cutting vertices
void make_comps(int u, int par_ei) {
  d[u] = l[u] = ++ts;
  int ch = 0;
  for (auto& [v, ei] : g[u]) {
    if (ei == par_ei) continue;  // case: tree-edge, from the other direction
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

    if ((par_ei == -1 && ch > 1) || (l[v] >= d[u])) {
      // case: u is a cutting vertex
      comp_sizes.push_back(0);
      while (st.top() != ei) {
        comp_sizes.back()++;
        st.pop();
      }
      comp_sizes.back()++;
      st.pop();
    }
  }
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  g.resize(n + 1);
  for (int ei = 0; ei < m; ei++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back({v, ei});
    g[v].push_back({u, ei});
  }

  l.resize(n + 1), d.resize(n + 1);
  make_comps(1, -1);
  comp_sizes.back() += st.size();

  cout << *max_element(comp_sizes.begin(), comp_sizes.end());
}
