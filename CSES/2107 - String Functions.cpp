#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();

  vector<int> z(n), p(n);

  int l = 0, r = 0;
  cout << '0';
  for (int i = 1; i < n; i++) {
    if (i + z[i - l] < r) z[i] = z[i - l];
    else {
      int c = max(0, r - i);
      while (i + c < n && s[c] == s[i + c]) c++;
      r = i + c;
      l = i;
      z[i] = c;
    }
    cout << ' ' << z[i];
  }
  cout << '\n';

  cout << '0';
  for (int i = 1; i < n; i++) {
    int m = p[i - 1];
    while (m > 0 && s[i] != s[m]) m = p[m - 1];
    p[i] = s[i] == s[m] ? m + 1 : 0;
    cout << ' ' << p[i];
  }
}
