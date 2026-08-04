#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int a, b;
  cin >> a;
  vector<pair<int, int>> events;
  while (cin >> a >> b) {
    events.push_back({a, 1});
    events.push_back({b, -1});
  }
  sort(events.begin(), events.end());
  int best = 0, curr = 0;
  for (auto [_, d] : events) best = max(best, curr += d);
  cout << best;
}
