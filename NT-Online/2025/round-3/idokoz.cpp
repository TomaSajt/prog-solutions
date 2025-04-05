#include <bits/stdc++.h>
using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  int at = stoi(a.substr(0, 2)) * 60 + stoi(a.substr(3, 2));
  int bt = stoi(b.substr(0, 2)) * 60 + stoi(b.substr(3, 2));
  if (bt < at) bt += 24 * 60;
  cout << bt - at;
}
