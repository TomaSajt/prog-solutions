#include <bits/stdc++.h>
using namespace std;

int cnt[4];

int main() {
  string s;
  getline(cin, s);
  getline(cin, s);
  for (int i = 0; i < s.size(); i++) {
    int m = i % 4;
    if (s[i] == 'P') cnt[m]++;
    if (s[i] == 'Z' && cnt[m] > 0) cnt[m]--;
  }
  cout << cnt[0] + cnt[1] + cnt[2] + cnt[3];
}
