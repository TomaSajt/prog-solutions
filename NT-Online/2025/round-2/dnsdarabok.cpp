#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  string s(n, '?');
  while (m--) {
    int i;
    cin >> i;
    i--;
    string p;
    cin >> p;
    for (int j = 0; j < p.size(); j++) {
      if (s[i + j] != '?' && s[i + j] != p[j]) {
        cout << "Hiba!";
        return 0;
      }
      s[i + j] = p[j];
    }
  }
  cout << s;
}
