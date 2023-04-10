#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  set<array<int, 3>> intervals;
  for (int i = 0; i < n; i++) {
    int s, e;
    cin >> s >> e;
    intervals.insert({s, e, i});
  }
  vector<int> times(n);
  int t = 0;
  while (!intervals.empty()) {
    t++;
    int prev_end = -1;
    while (true) {
      auto it = intervals.lower_bound({prev_end, INT_MAX, -1});
      if (it == intervals.end())
        break;
      prev_end = (*it)[1];
      times[(*it)[2]] = t;
      intervals.erase(it);
    }
  }
  cout << t << '\n';
  for (int tt : times)
    cout << tt << ' ';
}
