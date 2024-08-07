#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    char a, b;
    cin >> a >> b;
    cout << (a - '0') + (b - '0') << '\n';
  }
}
