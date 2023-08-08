#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);

  int n;
  cin >> n;

  set<string> teams;

  while (n--) {
    string s;
    cin >> s;

    sort(s.begin(), s.end());

    if (teams.count(s))
      teams.erase(s);
    else
      teams.insert(s);
  }

  cout << *teams.begin();
}
