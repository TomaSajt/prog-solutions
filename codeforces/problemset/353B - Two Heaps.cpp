#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  n *= 2;

  map<int, vector<int>> val_to_inds;
  vector<int> vals(n), sides(n, -1);
  for (int i = 0; i < n; i++) {
    cin >> vals[i];
    val_to_inds[vals[i]].push_back(i);
  }

  array<int, 2> cnts_uniq = {0, 0}, cnts = {0, 0};

  for (auto [_, inds] : val_to_inds) {
    if (inds.size() == 1) continue;
    cnts_uniq[0]++, cnts_uniq[1]++;
    for (int ind : inds) {
      int curr_side = cnts[0] > cnts[1];
      cnts[curr_side]++;
      sides[ind] = curr_side;
    }
  }

  for (auto [_, inds] : val_to_inds) {
    if (inds.size() != 1) continue;
    int curr_side = cnts[0] > cnts[1];
    cnts_uniq[curr_side]++;
    cnts[curr_side]++;
    sides[inds[0]] = curr_side;
  }

  cout << cnts_uniq[0] * cnts_uniq[1] << endl;
  for (int side : sides) {
    cout << side + 1 << ' ';
  }
}
