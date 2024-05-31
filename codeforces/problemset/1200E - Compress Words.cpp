#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(const string& s) {
  int n = s.size();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}

string get_merge_fragment(const string& base, const string& extra) {
  int bs = base.size(), es = extra.size();
  string base_end = bs > es ? base.substr(bs - es, es) : base;
  string h = extra + "#" + base_end;
  vector<int> p = prefix_function(h);
  return extra.substr(p.back());
}

int main() {
  int n;
  cin >> n;
  string merged = "";
  while (n--) {
    string s;
    cin >> s;
    merged += get_merge_fragment(merged, s);
  }
  cout << merged;
}
