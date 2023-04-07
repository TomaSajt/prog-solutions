#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i += 5) {
    int v = count(s.begin() + i, s.begin() + i + 5, '.');
    cout << (s[i + 4] == '-' ? v : 10 - v);
  }
}
