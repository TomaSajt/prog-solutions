#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, l, f;
  cin >> n >> k >> l >> f;

  bool alert = 0;
  int high_streak = 0, low_streak = 0;
  int res = 0;
  while (n--) {
    int a;
    cin >> a;
    if (a > f) {
      low_streak = 0;
      high_streak++;
    }
    else if (a < f) {
      low_streak++;
      high_streak = 0;
    }
    else {
      low_streak = 0;
      high_streak = 0;
    }
    if (high_streak >= k) {
      if (!alert) res++;
      alert = 1;
    }
    if (low_streak >= l) alert = 0;
  }
  cout << res;
}
