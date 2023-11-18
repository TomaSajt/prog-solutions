#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;

  vector<int> alt(n + 1, -1);
  for (int i = 0; i < n; i++) cin >> alt[i];

  vector<int> lens;
  int len = 1;
  for (int i = 1; i <= n; i++) {
    if (alt[i - 1] == alt[i]) {
      len++;
      continue;
    }
    if (len > 1) lens.push_back(len);
    len = 1;
  }

  if (lens.size() == 0) {
    cout << "-1";
    return 0;
  }

  map<int, int> len_cnt;
  for (int l : lens) len_cnt[l]++;
  cout << len_cnt.size() << '\n';

  int best_cnt = 0;
  for (auto& [l, cnt] : len_cnt) best_cnt = max(best_cnt, cnt);

  for (int l : lens) {
    if (len_cnt[l] != best_cnt) continue;
    cout << l;
    return 0;
  }
}
