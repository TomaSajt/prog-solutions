#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s, t;
  cin >> s >> t;

  int i = 0, j = 0;
  while (i < s.size() && j < t.size()) {
    if (s[i] == '?' || s[i] == t[j]) {
      s[i] = t[j];
      j++;
    }
    i++;
  }
  if (j != t.size()) {
    cout << "NO\n";
    return;
  }

  cout << "YES" << endl;
  while (i < s.size()) {
    if (s[i] == '?') s[i] = 'a';
    i++;
  }

  cout << s << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
