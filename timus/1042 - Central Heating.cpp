#include <bits/stdc++.h>
using namespace std;

// Gauss elimination in mod 2
int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;

  vector<vector<int>> mat(n, vector<int>(n + 1));

  for (int i = 0, a; i < n; i++) {
    while (cin >> a && a != -1) mat[a - 1][i] = 1;
    mat[i][n] = 1; // row sum is 1 mod 2 everywhere
  }

  // i: index of variable to eliminate
  for (int i = 0; i < n; i++) {
    // k: a row that still has the ith variable non-zero
    int k = -1;
    for (int j = i; j < n && k == -1; j++) {
      if (mat[j][i]) k = j;
    }
    assert(k != -1);
    swap(mat[i], mat[k]);
    // j: row to eliminate the i-th variable from
    for (int j = 0; j < n; j++) {
      if (i == j || !mat[j][i]) continue;
      for (int l = i; l <= n; l++) mat[j][l] ^= mat[i][l];
    }
  }

  for (int i = 0; i < n; i++) {
    if (mat[i][n]) cout << i + 1 << ' ';
  }
}
