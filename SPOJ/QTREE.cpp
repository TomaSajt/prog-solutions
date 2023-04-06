#include <bits/stdc++.h>
using namespace std;

struct segtree {
  vector<int> data;
  int size;
  segtree(const vector<int> &inp)
      : data(inp.size() * 4, INT_MIN), size(inp.size()) {
    build(inp, 0, 0, size);
  }
  void build(const vector<int> &inp, int x, int lx, int rx) {
    if (lx + 1 == rx) {
      data[x] = inp[lx];
      return;
    }
    int m = (lx + rx) / 2;
    build(inp, 2 * x + 1, lx, m);
    build(inp, 2 * x + 2, m, rx);
    data[x] = max(data[2 * x + 1], data[2 * x + 2]);
  }
  int get(int l, int r) { return get(l, r, 0, 0, size); }
  int get(int l, int r, int x, int lx, int rx) {
    if (rx <= l || r <= lx)
      return INT_MIN;
    if (l <= lx && rx <= r)
      return data[x];
    int m = (lx + rx) / 2;
    return max(get(l, r, 2 * x + 1, lx, m), get(l, r, 2 * x + 2, m, rx));
  }
  void set(int i, int v) { set(i, v, 0, 0, size); }
  void set(int i, int v, int x, int lx, int rx) {
    if (lx + 1 == rx) {
      data[x] = v;
      return;
    }
    int m = (lx + rx) / 2;
    if (i < m)
      set(i, v, 2 * x + 1, lx, m);
    else
      set(i, v, 2 * x + 2, m, rx);
    data[x] = max(data[2 * x + 1], data[2 * x + 2]);
  }
};

void builder_dfs(vector<int> &par, vector<vector<int>> &result,
                 const vector<vector<int>> &graph, int u) {
  for (int v : graph[u]) {
    if (par[u] == v)
      continue;
    par[v] = u;
    result[u].push_back(v);
    builder_dfs(par, result, graph, v);
  }
}

pair<vector<vector<int>>, vector<int>>
make_directed_tree(const vector<vector<int>> &graph, int root) {
  vector<int> par(graph.size(), -1);
  vector<vector<int>> result(graph.size());
  builder_dfs(par, result, graph, root);
  return {result, par};
}

void size_dfs(vector<vector<int>> &graph, vector<int> &sizes, int u) {
  sizes[u] = 1;
  for (int &v : graph[u]) {
    size_dfs(graph, sizes, v);
    sizes[u] += sizes[v];
    if (sizes[v] > sizes[graph[u][0]]) {
      // always have the node with the largest subtree in the first position
      swap(v, graph[u][0]);
    }
  }
}

void prepare_children_order(vector<vector<int>> &graph, int root) {
  vector<int> sizes(graph.size());
  size_dfs(graph, sizes, root);
}

void hld_dfs(int &t, const vector<vector<int>> &graph, vector<int> &in,
             vector<int> &out, vector<int> &nxt, int u) {
  in[u] = t++;
  for (int v : graph[u]) {
    // if this is the start of the heavy path, then set to nxt to self,
    // else set to the parent's nxt
    nxt[v] = (v == graph[u][0] ? nxt[u] : v);
    hld_dfs(t, graph, in, out, nxt, v);
  }
  out[u] = t;
}

array<vector<int>, 3> make_hld_arrays(const vector<vector<int>> &graph,
                                      int root) {
  int t = 0;
  vector<int> in(graph.size()), out(graph.size()), nxt(graph.size());
  hld_dfs(t, graph, in, out, nxt, root);
  return {in, out, nxt};
}

vector<vector<int>> make_logarithmic_parent_array(const vector<int> &par) {
  int n = par.size();
  int l = log2(n) + 2;
  vector<vector<int>> log_par(l, vector<int>(n));
  log_par[0] = par;
  for (int d = 1; d < l; d++) {
    for (int i = 0; i < n; i++) {
      log_par[d][i] = log_par[d - 1][log_par[d - 1][i]];
    }
  }
  return log_par;
}

int lca(const vector<vector<int>> &log_par, const vector<int> &hld_in,
        const vector<int> &hld_out, int u, int v) {
  auto is_in_subtree = [&](int a, int r) {
    return hld_in[r] <= hld_in[a] && hld_in[a] < hld_out[r];
  };

  if (is_in_subtree(u, v))
    return v;
  if (is_in_subtree(v, u))
    return u;
  for (int i = log_par.size() - 1; i >= 0; i--) {
    if (!is_in_subtree(v, log_par[i][u]))
      u = log_par[i][u];
  }
  return log_par[0][u];
}

int get_path_max_to_ancestor(segtree &st, vector<int> &hld_nxt,
                             vector<int> &hld_in, vector<int> &par, int a,
                             int r) {
  int res = INT_MIN;
  while (hld_nxt[a] != hld_nxt[r]) {
    res = max(res, st.get(hld_in[hld_nxt[a]], hld_in[a] + 1));
    a = par[hld_nxt[a]];
  }
  return max(res, st.get(hld_in[r] + 1, hld_in[a] + 1));
}

void solve(int n) {
  vector<vector<int>> undirected_graph(n + 1);
  map<pair<int, int>, int> vertex_pair_to_edge_index;
  vector<int> edge_index_to_original_cost(n);

  for (int i = 1; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    undirected_graph[a].push_back(b);
    undirected_graph[b].push_back(a);
    edge_index_to_original_cost[i] = c;
    vertex_pair_to_edge_index[minmax(a, b)] = i;
  }

  auto [graph, par] = make_directed_tree(undirected_graph, 1);
  par[0] = 0, par[1] = 1;

  auto log_par = make_logarithmic_parent_array(par);

  prepare_children_order(graph, 1);

  auto [hld_in, hld_out, hld_nxt] = make_hld_arrays(graph, 1);

  vector<int> data(n);
  data[0] = INT_MAX; // fake edge going up from node 1
  vector<int> edge_index_to_segtree_pos(n);
  for (int i = 2; i <= n; i++) {
    int pos = hld_in[i];
    auto vertex_pair = minmax(i, par[i]);
    int edge_index = vertex_pair_to_edge_index[vertex_pair];

    edge_index_to_segtree_pos[edge_index] = pos;
    data[pos] = edge_index_to_original_cost[edge_index];
  }
  segtree st(data);
  cin.ignore();
  string cmd;
  while (cin >> cmd && cmd[0] != 'D') {
    int x, y;
    cin >> x >> y;
    if (cmd[0] == 'Q') {
      int z = lca(log_par, hld_in, hld_out, x, y);
      int res1 = get_path_max_to_ancestor(st, hld_nxt, hld_in, par, x, z);
      int res2 = get_path_max_to_ancestor(st, hld_nxt, hld_in, par, y, z);
      cout << max(res1, res2) << '\n';
    } else {
      st.set(edge_index_to_segtree_pos[x], y);
    }
  }
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  while (cin >> n)
    solve(n);
}
