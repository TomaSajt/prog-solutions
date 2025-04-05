#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string best = "";
  vector<string> cand;
  while (n--) {
    string name;
    cin >> name;
    if (name.size() < 5) continue;
    if (set(name.begin(), name.end()).size() != name.size()) continue;
    cand.push_back(name);
  }
  if (cand.empty()) {
    cout << "Nincs";
    return 0;
  }
  sort(cand.begin(), cand.end(), [](string a, string b) {
    return (a.size() < b.size()) || (a.size() == b.size() && a > b);
  });
  cout << cand[0];
}
