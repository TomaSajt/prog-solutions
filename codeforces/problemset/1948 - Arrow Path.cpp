#include <bits/stdc++.h>
using namespace std;

int n;
array<string, 2> board;
vector<vector<bool>> vis;

void dfs(int r, int c) {
  if (vis[r][c])
    return;
  vis[r][c] = true;
  vector<array<int, 2>> opts;
  opts.push_back({1 - r, c});
  if (c != 0) opts.push_back({r, c - 1});
  if (c != n - 1) opts.push_back({r, c + 1});
  for (auto [nr, nc] : opts) {
    char c = board[nr][nc];
    if (c == '<')
      dfs(nr, nc - 1);
    else
      dfs(nr, nc + 1);
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> board[0] >> board[1];
    vis.assign(2, vector<bool>(n, false));

    dfs(0, 0);
    if (vis[1][n - 1])
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
