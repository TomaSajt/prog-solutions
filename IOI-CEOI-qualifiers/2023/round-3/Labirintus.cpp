// the code before the refactor was originally from mraron on njudge

#include <bits/stdc++.h>
using namespace std;

int M, R, C, BL, TR;
vector<vector<int>> labyrinth;
vector<int> sz, par;
stack<pair<int, int>> merged;

int get_root(int x) {
  if (x == par[x]) return x;
  return get_root(par[x]);
}

void merge_comps(int r1, int c1, int r2, int c2, bool push) {
  int x = r1 * C + c1;
  int y = r2 == R  ? BL :
          c2 == -1 ? BL :
          r2 == -1 ? TR :
          c2 == C  ? TR :
                     r2 * C + c2;
  x = get_root(x), y = get_root(y);
  if (x == y) return;
  if (sz[x] < sz[y]) swap(x, y);
  sz[x] += sz[y];
  par[y] = x;
  if (push) merged.push({x, y});
}

bool is_edge(int r, int c) { return r == -1 || r == R || c == -1 || c == C; }

void init_labyrinth(int r, int c, vector<vector<int>> l) {
  R = r, C = c;
  M = R * C;
  BL = M;
  TR = M + 1;
  labyrinth = l;
  sz.assign(M + 2, 1);
  par.resize(M + 2), iota(par.begin(), par.end(), 0);
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (labyrinth[i][j] == 0) continue;
      for (int x = i - 1; x <= i + 1; x++)
        for (int y = j - 1; y <= j + 1; y++) {
          if (!is_edge(x, y) && labyrinth[x][y] == 0) continue;
          merge_comps(i, j, x, y, 0);
        }
    }
  }
}

bool can_escape(int n, vector<int> u, vector<int> v) {
  for (int k = 0; k < n; k++) {
    int i = u[k], j = v[k];
    for (int x = i - 1; x <= i + 1; x++) {
      for (int y = j - 1; y <= j + 1; y++) {
        if (!is_edge(x, y) && labyrinth[x][y] == 0) continue;
        merge_comps(i, j, x, y, 1);
      }
    }
    labyrinth[i][j] = 1;
  }
  bool res = get_root(BL) != get_root(TR);
  while (!merged.empty()) {
    auto [x, y] = merged.top();
    par[y] = y;
    sz[x] -= sz[y];
    merged.pop();
  }

  for (int k = 0; k < n; k++) labyrinth[u[k]][v[k]] = 0;

  return res;
}
