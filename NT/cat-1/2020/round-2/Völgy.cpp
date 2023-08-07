#include <bits/stdc++.h>
using namespace std;

int n;

int solve(const vector<int>& heights) {
  int best_width = 0;
  vector<int> prev(n);
  prev[0] = -1;
  for (int i = 1; i < n; i++) {
    prev[i] = i - 1;
    while (prev[i] != -1 && heights[i] > heights[prev[i]]) prev[i] = prev[prev[i]];
    if (prev[i] != -1) best_width = max(best_width, i - prev[i]);
  }
  return best_width;
}

int main() {
  cin >> n;
  vector<int> heights(n);
  for (int& h : heights) cin >> h;
  int res1 = solve(heights);
  reverse(heights.begin(), heights.end());
  int res = max(res1, solve(heights));
  if (res < 2) {
    cout << -1;
    return 0;
  }
  cout << res;
}
