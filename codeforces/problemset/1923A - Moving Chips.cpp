#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int& a : x) cin >> a;
    int first = -1;
    int last = -1;
    for (int i = 0; i < n; i++) {
      if (!x[i]) continue;
      if (first == -1) first = i;
      last = i;
    }
    cout << count(x.begin() + first, x.begin() + last, 0) << '\n';
  }
}
