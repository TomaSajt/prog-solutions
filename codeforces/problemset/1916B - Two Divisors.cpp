#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    cout << (b % a == 0 ? b * (b / a) : lcm(a, b)) << '\n';
  }
}
