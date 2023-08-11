#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  string z = "hello";
  int zi = 0;

  for (int si = 0; zi < z.size() && si < s.size(); si++) {
    if (s[si] == z[zi]) zi++;
  }

  cout << (zi == z.size() ? "YES" : "NO");
}
