#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  for (int i = -n; i <= n; i++) {
    for (int j = -n; j <= n; j++) {
      int val = 5 - abs(i) - abs(j);
      cout << (char)(val < 0 ? ' ' : ('0' + val)) << ' ';
    }
    cout << '\n';
  }
}
