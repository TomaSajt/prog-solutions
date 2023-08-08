#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> stamps(n);
  for (int& s : stamps) cin >> s;

  vector<int> stamps_needed(k + 1, INT_MAX / 2);
  stamps_needed[0] = 0;

  for (int i = 1; i <= k; i++) {
    for (int s : stamps) {
      if (i >= s) stamps_needed[i] = min(stamps_needed[i], stamps_needed[i - s] + 1);
    }
  }

  cout << *max_element(stamps_needed.begin(), stamps_needed.end());
}
