#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(), cin.tie(0);
  int n;
  string a, b;
  cin >> n >> a >> b;
  int pos_a = 0, pos_b = 0;
  for (int i = 0; i < n; i++) {
    pos_a += a[i] == 'J';
    pos_b += b[i] == 'J';
    if (pos_a == pos_b) {
      cout << i + 2;
      return 0;
    }
  }
  cout << -1;
}
