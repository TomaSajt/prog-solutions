// "inspired by" solution by SleepyOverlord on njudge
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0), cin.sync_with_stdio(0);

  int n, k, m;
  cin >> n >> k >> m;

  vector<int> pos_color(n + 2);
  for (int i = 1; i <= n; i++) cin >> pos_color[i];

  vector<array<int, 2>> instrs(m);
  for (auto& [c, x] : instrs) cin >> c >> x;
  reverse(instrs.begin(), instrs.end());

  // calculates in reverse what was the position of the people
  // who reached their respective side last
  int left_pos = 0, right_pos = n + 1;
  for (auto& [c, x] : instrs) {
    if (x == -1 && c == pos_color[left_pos + 1]) left_pos++;
    if (x == +1 && c == pos_color[left_pos]) left_pos--;

    if (x == +1 && c == pos_color[right_pos - 1]) right_pos--;
    if (x == -1 && c == pos_color[right_pos]) right_pos++;
  }

  cout << left_pos + (n + 1 - right_pos);
}
