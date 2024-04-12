#include <bits/stdc++.h>
using namespace std;

int main() {
  int N = 101;
  vector<int> d(N);
  int row = 0;

  auto mult3 = [&]() {
    d.insert(d.begin(), 0);
    d.resize(N);
  };
  auto div3 = [&]() {
    d.erase(d.begin());
    d.resize(N);
  };
  auto inc = [&]() {
    int i = 0;
    while (d[i] == 2) {
      d[i] = 0;
      i++;
    }
    d[i]++;
  };
  auto dec = [&]() {
    int i = 0;
    while (d[i] == 0) {
      d[i] = 2;
      i++;
    }
    d[i]--;
  };

  int k;
  cin >> k;
  while (k--) {
    int op;
    cin >> op;
    if (op == 0) mult3(), row++;
    else if (op == 1) mult3(), inc(), row++;
    else if (op == 2) mult3(), inc(), inc(), row++;
    else if (op == 3) div3(), row--;
    else if (op == 4) dec();
    else if (op == 5) inc();
  }

  cout << row << '\n';

  auto it = find_if(d.rbegin(), d.rend(), [](int a) { return a != 0; });
  if (it == d.rend()) it--;
  while (it != d.rend()) {
    cout << *it;
    it++;
  }
}
