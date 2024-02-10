#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;

  vector<array<int, 2>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  vector<vector<int>> is_wall(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> is_wall[i][j];
    }
  }

  vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
  queue<array<int, 2>> q;
  dist[n / 2][n / 2] = 0;
  q.push({n / 2, n / 2});

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (auto [dx, dy] : dirs) {
      int nx = x + dx, ny = y + dy;
      if (nx < 0 || nx >= n || ny < 0 || ny > n || is_wall[nx][ny] || dist[nx][ny] != INT_MAX) continue;
      dist[nx][ny] = dist[x][y] + 1;
      q.push({nx, ny});
    }
  }

  vector<int> res = {dist[0][0], dist[0][n - 1], dist[n - 1][0], dist[n - 1][n - 1]};

  int worst = *max_element(res.begin(), res.end());
  if (worst == INT_MAX) {
    cout << "NINCS";
    return 0;
  }

  for (int i = 0; i < 4; i++) {
    if (res[i] == worst) cout << "ABCD"[i];
  }
  cout << endl;
}
