#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  if (n > m) swap(n, m);

  auto possible = [&](int k) {
    int k2 = k * k;
    return n >= k2 / 2 && m >= (k2 + 1) / 2;
  };

  /*

  int sol = -1;
  for (int k = 1; k <= 1500; k++) {
    if (!possible(k)) {
      sol = k - 1;
      break;
    }
  }
  cout << sol;

  */

  int l = 0, r = 1500;
  while (l < r - 1) {
    int m = (l + r) / 2;
    if (possible(m)) {
      l = m;
    }
    else {
      r = m;
    }
  }
  cout << l;

  /*

  int sqrt_2n = sqrt(2 * n);
  int sqrt_2np1 = sqrt(2 * n + 1);
  if (m > n && sqrt_2n % 2 == 0 && sqrt_2np1 % 2 == 1) {
    cout << sqrt_2n + 1;
  }
  else {
    cout << sqrt_2n;
  }

  */
}
