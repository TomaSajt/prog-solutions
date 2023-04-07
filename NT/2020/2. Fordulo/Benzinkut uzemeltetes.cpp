#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<int> tot_val(n), pos(n), val(n), prev(n, -1);

  for (int i = 0; i < n; i++) {
    cin >> pos[i] >> val[i];
    for (int j = 0; j < i; j++) {
      if (pos[i] - pos[j] >= k && tot_val[i] < tot_val[j]) {
        tot_val[i] = tot_val[j];
        prev[i] = j;
      }
    }
    tot_val[i] += val[i];
  }
  int curr = max_element(tot_val.begin(), tot_val.end()) - tot_val.begin();
  cout << tot_val[curr] << '\n';
  stack<int> res;
  while (curr != -1) {
    res.push(curr);
    curr = prev[curr];
  }
  cout << res.size();
  while (!res.empty()) {
    cout << ' ' << res.top() + 1;
    res.pop();
  }
}
