#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin >> n;
  vector<pair<int, int>> intervals(n);
  for (auto& [s, e] : intervals) {
    cin >> s >> e;
  }

  sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) { return a.second < b.second; });

  int lastTimestamp = 0;
  vector<int> timestamps;
  for (auto& [s, e] : intervals) {
    if (s > lastTimestamp) {
      lastTimestamp = e - 1;
      timestamps.push_back(lastTimestamp);
    }
  }

  cout << timestamps.size() << '\n';
  for (int ts : timestamps) {
    cout << ts << ' ';
  }
}
