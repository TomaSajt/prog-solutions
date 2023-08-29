#include <bits/stdc++.h>
using namespace std;

ostream& operator<<(ostream& s, const pair<int, int>& p) {
  return s << p.first << ' ' << p.second;
}

pair<int, int> get_res(map<int, int>& cnt_map) {
  return *max_element(cnt_map.begin(), cnt_map.end(), [](auto& p1, auto& p2) { return p1.second < p2.second; });
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  int max_less_ind = -1, min_more_ind = -1;
  map<int, int> max_less_ind_cnt, min_more_ind_cnt;

  vector<int> scores(n + 1);
  for (int i = 1; i <= n; i++) cin >> scores[i];
  bool track = 0;
  for (int i = 1; i <= n; i++) {
    if (i == m) track = 1;

    if (scores[i] > scores[m] && (min_more_ind == -1 || scores[i] < scores[min_more_ind])) min_more_ind = i;
    if (scores[i] < scores[m] && (max_less_ind == -1 || scores[i] > scores[max_less_ind])) max_less_ind = i;

    if (!track) continue;
    if (max_less_ind != -1) max_less_ind_cnt[max_less_ind]++;
    if (min_more_ind != -1) min_more_ind_cnt[min_more_ind]++;
  }

  if (min_more_ind == -1)
    cout << -1 << '\n';
  else
    cout << get_res(min_more_ind_cnt) << '\n';

  if (max_less_ind == -1)
    cout << -1;
  else
    cout << get_res(max_less_ind_cnt);
}
