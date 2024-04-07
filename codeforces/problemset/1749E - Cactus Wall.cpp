#include <bits/stdc++.h>
using namespace std;

vector<array<int, 2>> diffs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<array<int, 2>> ddiffs = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> board(n, vector<bool>(m));
  vector<vector<array<int, 2>>> par(n, vector<array<int, 2>>(m, {-1, -1}));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      board[i][j] = c == '#';
    }
  }

  auto in_bounds = [&](int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m;
  };

  auto blocked = [&](int i, int j) {
    for (auto& [di, dj] : diffs) {
      int ni = i + di, nj = j + dj;
      if (in_bounds(ni, nj) && board[ni][nj]) return true;
    }
    return false;
  };

  deque<array<int, 2>> q;
  for (int i = 0; i < n; i++) {
    if (blocked(i, 0)) continue;
    if (board[i][0]) q.push_front({i, 0});
    else q.push_back({i, 0});
    par[i][0] = {-2, -2};
  }

  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop_front();
    if (j == m - 1) {
      cout << "YES\n";
      while (i != -2) {
        board[i][j] = true;
        auto& [ni, nj] = par[i][j];
        i = ni, j = nj;
      }
      for (int ii = 0; ii < n; ii++) {
        for (int jj = 0; jj < m; jj++) {
          cout << ".#"[board[ii][jj]];
        }
        cout << '\n';
      }
      return;
    };
    for (auto& [di, dj] : ddiffs) {
      int ni = i + di, nj = j + dj;
      if (!in_bounds(ni, nj) || par[ni][nj][0] != -1) continue;
      if (blocked(ni, nj)) continue;
      par[ni][nj] = {i, j};
      if (board[ni][nj]) q.push_front({ni, nj});
      else q.push_back({ni, nj});
    }
  }
  cout << "NO\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
