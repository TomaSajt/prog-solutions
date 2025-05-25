#include <bits/stdc++.h>
#define int int64_t

using namespace std;

int32_t main() {
  string a, b;
  cin >> a >> b;
  int i = 0;
  while (a[i] == b[i]) i++;
  string beg = a.substr(0, i);
  a = a.substr(i);
  b = b.substr(i);
  if (a == "") {
    if (b == "a") {
      cout << "-1";
      return 0;
    }
    cout << beg << (b[0] - 1);
    return 0;
  }
  if (b[0] - a[0] >= 2) {
    cout << beg << (b[0] - 1);
    return 0;
  }
  assert(b[0] - a[0] == 1);
  if(b.size() > 1) {
    cout << beg << b[0];
    return 0;
  }
  cout << beg << a[0];
}
