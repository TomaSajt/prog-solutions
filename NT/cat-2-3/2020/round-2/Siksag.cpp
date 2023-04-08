#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int prev, other = -1;
  cin >> prev;
  int start = 1;
  int consecutive_start = 1;
  int best_start = 1;
  int best_end = 1;
  for (int i = 2; i <= n; i++) {
    int curr;
    cin >> curr;
    if (curr == prev) {
    } else if (curr == other) {
      consecutive_start = i;
      swap(prev, other);
    } else if ((other == -1 && abs(curr - prev) == 1) ||
               (other != -1 && curr - prev == prev - other)) {
      start = consecutive_start;
      consecutive_start = i;
      other = prev;
      prev = curr;
    } else {
      start = i;
      consecutive_start = i;
      other = -1;
      prev = curr;
    }
    if (best_end - best_start < i - start) {
      best_end = i;
      best_start = start;
    }
  }
  cout << best_end - best_start + 1 << ' ' << best_start;
}
