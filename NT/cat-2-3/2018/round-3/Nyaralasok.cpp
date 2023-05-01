#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, f;
  cin >> n >> f;

  vector<int> v(n);
  for (int& a : v) cin >> a;

  array<int, 3> best = {0, 1, 2};
  int best_s = v[0] - v[1] - v[2];
  if (best_s > f) {
    cout << "-1";
    return 0;
  }

  for (int i = 0; i < n - 2; i++) {
    if (v[i] + v[i + 1] + v[i + 2] > f) break;
    int j = i + 1, k = n - 1;
    while (j < k) {
      while (v[i] + v[j] + v[k] > f) k--;
      while (j < k && v[i] + v[j] + v[k] <= f) {
        int s = v[i] + v[j] + v[k];
        if (s > best_s) {
          best_s = s;
          best = {i, j, k};
        }
        j++;
      }
    }
  }
  for (int& i : best) cout << i + 1 << ' ';
}
