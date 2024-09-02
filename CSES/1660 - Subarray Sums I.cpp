#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int& ai : a) cin >> ai;
  int l = 0, r = 0;
  int s = 0;
  int res = 0;
  while (true) {
    if (s <= x) {
      if (r < n) {
        s += a[r++];
        if (s == x) res++;
      }
      else break;
    }
    else {
      s -= a[l++];
      if (s == x) res++;
    }
  }
  cout << res;
}
