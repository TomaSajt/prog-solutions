#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  map<int, int> last_seen_sum;
  last_seen_sum[0] = 0;
  int sum = 0;
  pair<int, int> best;
  int bestD = INT_MAX;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    sum = (sum + a) % k;
    if (last_seen_sum.count(sum)) {
      int j = last_seen_sum[sum];
      int d = i - j;
      if (d < bestD) {
        bestD = d;
        best = {j + 1, i};
      }
    }
    last_seen_sum[sum] = i;
  }
  if (best.first == 0)
    cout << "-1";
  else
    cout << bestD << '\n' << best.first << ' ' << best.second;
}
