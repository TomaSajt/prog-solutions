#include <bits/stdc++.h>
using namespace std;
#define int int64_t

pair<int, int> get_cnt(int n, int base, int digit) {
  int len = 0;
  int cnt = 0;
  while (n > 0) {
    len++;
    cnt += (n % base == digit);
    n /= base;
  }
  return {len, cnt};
}

int32_t main() {
  int n, k;
  cin >> n >> k;

  int best_cnt = 0;

  // bases where n's repr is longer than 2
  {
    int b = k + 1;
    while (true) {
      auto [len, cnt] = get_cnt(n, b, k);
      if (len <= 2) break;
      // if (len <= best_cnt) break;
      best_cnt = max(best_cnt, cnt);
      b++;
    }
  }

  if (n % k == 0) {
    int b = n / k - 1;
    if (b > k) {
      best_cnt = max((int)2, best_cnt);
    }
  }

  // assume n = coef*base + k
  /*
  {
    int asd = n - k;
    for (int coef = 1; coef * coef < asd; coef++) {
      if (asd % coef != 0) continue;
      int base = asd / coef;
      if (base <= k) continue;
      // cout << coef << " * " << base << " + " << k << " = " << n << endl;
      int cnt = coef == k ? 2 : 1;
      best_cnt = max(best_cnt, cnt);
    }
  }*/

  /*
  {
    for (int base = n / k; (k + 1) * base > n; base--) {
      int rem = n - k * base;
      cout << k << " * " << base << " + " << rem << " = " << n << endl;

      int cnt = rem == k ? 2 : 1;
      best_cnt = max(best_cnt, cnt);
    }
  }
  */

  // cout << 0 << endl;
  cout << best_cnt << endl;
}
