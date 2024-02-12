#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();

  vector<int> z(n);
  int l = 0, r = 0;
  for (int i = 1; i < n; i++) {
    if (i + z[i - l] < r) z[i] = z[i - l];
    else {
      int c = max(0, r - i);
      while (i + c < n && s[c] == s[i + c]) c++;
      r = i + c;
      l = i;
      z[i] = c;
    }
  }

  int infix_max_len = 0;

  for (int i = 1; i < n; i++) {
    int len = i + z[i] == n ? z[i] - 1 : z[i]; // drop last char, if this was a suffix
    infix_max_len = max(infix_max_len, len);
  }

  int best_i = INT_MAX;
  for (int i = 1; i < n; i++) {
    if (i + z[i] != n) continue; // skip infixes
    if (infix_max_len >= z[i]) {
      best_i = min(best_i, i);
    }
  }
  if (best_i == INT_MAX) {
    cout << "Just a legend";
  }
  else {
    cout << s.substr(best_i);
  }
}
