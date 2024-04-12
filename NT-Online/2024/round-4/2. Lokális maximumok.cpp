#include <bits/stdc++.h>
using namespace std;

const int MIN = 1, MAX = 2;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (int& xi : x) cin >> xi;
  vector<pair<int, int>> ex;
  for (int i = 1; i < n - 1; i++) {
    if (x[i] > max(x[i - 1], x[i + 1])) ex.push_back({i, MAX});
    if (x[i] < min(x[i - 1], x[i + 1])) ex.push_back({i, MIN});
  }
  int m = ex.size();
  int best_i = 0;
  int best_j = INT_MAX;
  for (int ind = 1; ind < m - 1; ind++) {
    if (ex[ind - 1].second == MAX && ex[ind].second == MIN && ex[ind + 1].second == MAX) {
      int i = ex[ind - 1].first;
      int j = ex[ind + 1].first;
      if (j - i < best_j - best_i) best_i = i, best_j = j;
    }
  }
  if (best_j == INT_MAX) cout << -1;
  else cout << best_i + 1 << ' ' << best_j + 1;
}
