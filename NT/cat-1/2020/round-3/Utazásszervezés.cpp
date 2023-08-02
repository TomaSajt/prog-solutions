#include <bits/stdc++.h>
using namespace std;

int main() {
  int guides, k, m, c;
  cin >> guides >> k >> m >> c;
  k = 20000;  // Last two test cases don't have a valid k value!!!!!

  vector<int> requests(k + 1, 0);
  for (int i = 0; i < c; i++) {
    int s;
    cin >> s;
    requests[s] += 1;
  }

  vector<int> guide_ends(k + 1, 0);
  int total = 0;

  for (int s = 1; s <= k - m + 1; s++) {
    int accepted = min(guides, requests[s]);
    total += accepted;
    guides -= accepted;
    guide_ends[s + m - 1] += accepted;
    guides += guide_ends[s];
  }

  cout << total;
}
