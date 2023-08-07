#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, m;
  cin >> n >> m;
  if (n > m) swap(n, m);

  if (n == 1) {
    if (m == 1) {
      cout << 1;
    }
    else {
      cout << m - 2;
    }
  }
  else {
    cout << (n - 2) * (m - 2);
  }
}
