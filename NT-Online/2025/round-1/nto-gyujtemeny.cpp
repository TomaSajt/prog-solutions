#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n, m;
  cin >> n >> m;

  set<int> s;
  while (n--) {
    int k;
    cin >> k;
    while (k--) {
      int p;
      cin >> p;
      s.insert(p);
    }
  }

  cout << (s.size() == m ? "IGEN" : "NEM");
}
