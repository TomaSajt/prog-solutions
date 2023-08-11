#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, r = 1;
  cin >> n;
  while (n--) r = (r * 2) % 1000000007;
  cout << r;
}
