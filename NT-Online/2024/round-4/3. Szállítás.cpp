#include <bits/stdc++.h>
using namespace std;

int lis_pos(vector<int>& x, int k) {
  vector<int> v;
  for (int xi : x) {
    int pos = upper_bound(v.begin(), v.end(), xi) - v.begin();
    if (pos >= v.size()) v.push_back(xi);
    else v[pos] = xi;
    if (xi == k) return pos;
  };
  return -1;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> x(n);
  for (int& xi : x) cin >> xi;

  vector<int> x2 = x;
  reverse(x2.begin(), x2.end());
  for (int& xi : x) xi = -xi;
  cout << lis_pos(x, -k) + lis_pos(x2, k) + 1;
}
