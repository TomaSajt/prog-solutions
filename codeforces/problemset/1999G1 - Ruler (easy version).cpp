#include <bits/stdc++.h>
using namespace std;

void solve() {
  int num = 0;
  int l = 1, r = 1000;
  while (l + 1 < r) {
    int a = l + (r - l) / 2;
    cout << "? 1 " << a << endl;

    int area;
    cin >> area;

    if (area == a) l = a;
    else r = a;
  }
  cout << "! " << l + 1 << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
