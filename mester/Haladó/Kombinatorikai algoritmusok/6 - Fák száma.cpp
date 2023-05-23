#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> db(n + 1);
  db[1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < i; j++) db[i] += db[j] * db[i - j];
  }
  cout << db[n] << endl;
}
