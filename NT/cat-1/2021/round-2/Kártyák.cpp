#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> a(n);
  for (auto& ai : a) cin >> ai;

  int sum = accumulate(a.begin(), a.end(), 0);

  if (sum % n != 0) {
    cout << "NEM\n";
    cout << n - (sum % n);
    return 0;
  }

  cout << "IGEN\n";

  int avg = sum / n;

  for (auto& ai : a) {
    cout << max(ai - avg, 0) << ' ';
  }
}
