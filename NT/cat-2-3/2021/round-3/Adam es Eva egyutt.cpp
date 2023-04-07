#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int an;
  cin >> an >> an;
  vector<array<int, 2>> av(an);
  for (auto &[s, e] : av)
    cin >> s >> e;
  int en;
  cin >> en;
  vector<array<int, 2>> ev(en);
  for (auto &[s, e] : ev)
    cin >> s >> e;

  vector<array<int, 2>> res;
  int ai = 0, ei = 0;
  while (ai < an && ei < en) {
    auto [as, ae] = av[ai];
    auto [es, ee] = ev[ei];
    if (ae <= es) {
      ai++;
    } else if (ee <= as) {
      ei++;
    } else if (ae < ee) {
      res.push_back({max(as, es), ae});
      ai++;
    } else {
      res.push_back({max(as, es), ee});
      ei++;
    }
  }
  cout << res.size() << '\n';
  for (auto &[s, e] : res)
    cout << s << ' ' << e << '\n';
}
