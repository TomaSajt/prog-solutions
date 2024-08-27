#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n;
  while (cin >> n >> s) {
    sort(s.begin(), s.end());
    cout << s << '\n';
  }
}
