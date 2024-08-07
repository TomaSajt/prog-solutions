#include <bits/stdc++.h>
using namespace std;

void solve() {
  int num = 0;
  int l = 1, r = 1000;
  while (l + 1 < r) {
    int a = l + (r - l) / 3;
    int b = l + 2 * (r - l) / 3;
    cout << "? " << a << " " << b << endl;
    int area;
    cin >> area;

    int area0 = a * b;
    int area1 = a * (b + 1);
    int area2 = (a + 1) * (b + 1);

    if (area == area0) l = b;
    else if (area == area1) l = a, r = b;
    else if (area == area2) r = a;
    else cout << 1 / 0;
  }
  cout << "! " << l + 1 << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
