#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m, s, e;
  cin >> n >> m >> s >> e;
  vector<vector<int>> station_to_lines(m + 1);
  vector<vector<int>> line_to_stations(n + 1);
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    while (a--) {
      int b;
      cin >> b;
      line_to_stations[i].push_back(b);
      station_to_lines[b].push_back(i);
    }
  }
  vector<bool> used_line(n + 1);
  vector<int> prev_station(m + 1);
  vector<int> reached_with_line(m + 1);
  vector<int> dist(m + 1, -1);
  dist[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int curr_station = q.front();
    q.pop();
    for (int &line : station_to_lines[curr_station]) {
      if (used_line[line])
        continue;
      used_line[line] = 1;
      for (int &next_station : line_to_stations[line]) {
        if (dist[next_station] != -1)
          continue;
        dist[next_station] = dist[curr_station] + 1;
        prev_station[next_station] = curr_station;
        reached_with_line[next_station] = line;
        q.push(next_station);
      }
    }
  }

  cout << dist[e] << endl;
  if (dist[e] == -1)
    return 0;

  stack<int> res;
  int curr_station = e;
  while (curr_station != s) {
    res.push(reached_with_line[curr_station]);
    curr_station = prev_station[curr_station];
  }
  while (!res.empty()) {
    cout << res.top() << ' ';
    res.pop();
  }
}
