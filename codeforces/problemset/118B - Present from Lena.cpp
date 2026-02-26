#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  for (int i = -n; i <= n; i++) {
    int ai = abs(i);
    cout << string(2 * ai, ' ');
    int val = n - ai;
    for (int j = 0; j <= val - 1; j++) cout << j << ' ';
    cout << val;
    for (int j = val - 1; j >= 0; j--) cout << ' ' << j;
    cout << '\n';
  }
}
