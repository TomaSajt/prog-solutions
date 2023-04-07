#include <bits/stdc++.h>
using namespace std;

int main() {
  int y, x, l, n;
  cin >> y >> x >> l >> n;
  cout << max({0, n + y - x, l + n - x});
}
