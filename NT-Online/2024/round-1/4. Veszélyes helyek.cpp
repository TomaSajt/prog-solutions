#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m;
  cin >> n >> m;

  vector<vector<int>> dangers(n + 2, vector<int>(m, INT_MAX));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> dangers[i][j];
    }
  }

  for (int j = m - 2; j >= 0; j--) {
    for (int i = 1; i <= n; i++) {
      dangers[i][j] += min({dangers[i + 1][j + 1], dangers[i][j + 1], dangers[i - 1][j + 1]});
    }
  }

  int bestI = 0;
  for (int i = 1; i <= n; i++) {
    if (dangers[i][0] < dangers[bestI][0]) bestI = i;
  }
  cout << bestI;
}
