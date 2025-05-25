#include <bits/stdc++.h>
#define int int64_t

using namespace std;

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> mat(n, vector<int>(m));
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < m; col++) {
      cin >> mat[row][col];
    }
  }

  vector<array<int, 5>> res;

  for (int row = 0; row < n; row++) {
    for (int col = m - 1; col >= 3; col--) {
      res.push_back({row + 1, col - 3 + 1, row + 1, col - 1 + 1, mat[row][col]});
      mat[row][col - 1] += mat[row][col];
      mat[row][col - 2] += mat[row][col];
      mat[row][col - 3] += mat[row][col];

      res.push_back({row + 1, col - 2 + 1, row + 1, col + 1, -mat[row][col]});
      mat[row][col - 2] -= mat[row][col];
      mat[row][col - 1] -= mat[row][col];
      mat[row][col] -= mat[row][col];
    }
  }

  for (int col = 0; col < 3; col++) {
    for (int row = n - 1; row >= 3; row--) {
      res.push_back({row - 3 + 1, col + 1, row - 1 + 1, col + 1, mat[row][col]});
      mat[row - 1][col] += mat[row][col];
      mat[row - 2][col] += mat[row][col];
      mat[row - 3][col] += mat[row][col];

      res.push_back({row - 2 + 1, col + 1, row + 1, col + 1, -mat[row][col]});
      mat[row - 2][col] -= mat[row][col];
      mat[row - 1][col] -= mat[row][col];
      mat[row][col] -= mat[row][col];
    }
  }

  int target = max({mat[0][0], mat[1][0], mat[2][0]}) + 1;
  for (int row = 0; row < 3; row++) {
    int d = target - mat[row][0];
    res.push_back({row + 1, 0 + 1, row + 1, 2 + 1, d});
    mat[row][0] += d;
    mat[row][1] += d;
    mat[row][2] += d;
  }
  for (int col = 0; col < 3; col++) {
    if (mat[0][col] != mat[1][col] || mat[0][col] != mat[2][col]) {
      cout << "NO";
      return 0;
    }
    res.push_back({0 + 1, col + 1, 2 + 1, col + 1, -mat[0][col]});
    mat[0][col] -= mat[0][col];
    mat[1][col] -= mat[1][col];
    mat[2][col] -= mat[2][col];
  }

  cout << "YES" << endl;
  cout << res.size() << endl;
  for (auto arr : res) {
    for (int a : arr) cout << a << ' ';
    cout << endl;
  }

  /*
    for (int row = 0; row < n; row++) {
      for (int col = 0; col < m; col++) {
        cout << mat[row][col] << ' ';
      }
      cout << endl;
    }*/
}
