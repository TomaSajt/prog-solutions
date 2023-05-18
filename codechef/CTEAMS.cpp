#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  set<pair<int, int>> youngSet, oldSet;
  int youngSum = 0, oldSum = 0;
  while (n--) {
    pair<int, int> p;
    cin >> p.first >> p.second;
    if (!youngSet.empty() && youngSet.rbegin()->first >= p.first) {
      youngSet.insert(p);
      youngSum += p.second;
    }
    else {
      oldSet.insert(p);
      oldSum += p.second;
    }

    if (youngSet.size() > oldSet.size() + 1) {
      pair<int, int> p = *youngSet.rbegin();
      youngSet.erase(p);
      youngSum -= p.second;
      oldSet.insert(p);
      oldSum += p.second;
    }
    if (oldSet.size() > youngSet.size()) {
      pair<int, int> p = *oldSet.begin();
      oldSet.erase(p);
      oldSum -= p.second;
      youngSet.insert(p);
      youngSum += p.second;
    }
    cout << abs(youngSum - oldSum) << '\n';
  }
}
