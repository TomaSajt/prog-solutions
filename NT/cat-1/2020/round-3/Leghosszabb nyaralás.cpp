#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, p;
  cin >> n >> p;

  vector<int> costs(n);
  for (auto& c : costs) cin >> c;

  int total_cost = 0;
  int best_length = 0;

  int l = 0;
  for (int r = 0; r < n; r++) {
    total_cost += costs[r];
    while (total_cost > p) {
      total_cost -= costs[l];
      l++;
    }
    best_length = max(best_length, r - l + 1);
  }

  cout << best_length;
}
