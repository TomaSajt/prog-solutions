#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  for (int& hi : h) cin >> hi;

  int len = 1, best_len = 1, cnt = 0;
  for (int i = 1; i < n; i++) {
    if (h[i - 1] == h[i]) {
      len = 1;
      continue;
    }
    if (len == 1) cnt++;
    len++;
    best_len = max(best_len, len);
  }
  cout << cnt << '\n';
  cout << (cnt == 0 ? -1 : best_len);
}
