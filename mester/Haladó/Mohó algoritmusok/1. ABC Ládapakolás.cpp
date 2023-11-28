// 92/100 for some reason

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  queue<int> a_poses;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 'A') a_poses.push(i);
    else if (s[i] == 'B') {
      if (a_poses.empty()) continue;
      s[i] = ' ';
      s[a_poses.front()] = 'B';
      a_poses.pop();
    }
  }

  queue<int> b_poses;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 'B') b_poses.push(i);
    else if (s[i] == 'C') {
      if (b_poses.empty()) continue;
      s[i] = ' ';
      s[b_poses.front()] = 'C';
      b_poses.pop();
    }
  }

  a_poses = {};
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 'A') a_poses.push(i);
    else if (s[i] == 'C') {
      if (a_poses.empty()) continue;
      s[i] = ' ';
      s[a_poses.front()] = 'C';
      a_poses.pop();
    }
  }

  cout << n - count(s.begin(), s.end(), ' ');
}
