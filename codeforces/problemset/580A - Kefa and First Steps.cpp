#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int best_len = 0, curr_len = 0, curr_max = -1;
  while (n--) {
    int a;
    cin >> a;
    if (a >= curr_max) {
      curr_max = a;
      curr_len += 1;
      best_len = max(best_len, curr_len);
    }
    else {
      curr_len = 1;
      curr_max = a;
    }
  }

  cout << best_len;
}
