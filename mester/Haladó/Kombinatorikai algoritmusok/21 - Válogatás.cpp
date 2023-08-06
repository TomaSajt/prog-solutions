#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> data(n, vector<int>(n));

  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> data[i][j];
      sum += data[i][j];
    }
  }

  vector<int> curr_perm(n);
  iota(curr_perm.begin(), curr_perm.end(), 0);

  int best_moved = INT_MAX;
  vector<int> best_perm;

  do {
    int moved = sum;
    for (int i = 0; i < n; i++) {
      moved -= data[i][curr_perm[i]];
    }
    if (moved < best_moved) {
      best_moved = moved;
      best_perm = curr_perm;
    }
  } while (next_permutation(curr_perm.begin(), curr_perm.end()));

  cout << best_moved << '\n';
  for (auto& p : best_perm) cout << p + 1 << ' ';
}
