#include <bits/stdc++.h>
using namespace std;

int p_val(const string& s) {
  int n = s.size();
  vector<int> pi(n);
  int best = 0;
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi[n - 1];
}

string find_palin(const string& s) {
  string r = s;
  reverse(r.begin(), r.end());
  string w1 = s + '#' + r;
  string w2 = r + '#' + s;
  int m1 = p_val(w1);
  int m2 = p_val(w2);
  return m1 >= m2 ? w1.substr(0, m1) : w2.substr(0, m2);
}

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  int a = 0;
  while (a < n / 2 && s[a] == s[n - a - 1]) a++;
  cout << s.substr(0, a) << find_palin(s.substr(a, n - 2 * a)) << s.substr(n - a, a) << endl;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
