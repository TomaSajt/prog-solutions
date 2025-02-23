#include <bits/stdc++.h>
using namespace std;
#define int  int64_t
#define uint uint64_t

uint calc_hash(string& s) {
  uint hash = 0;
  for (char c : s) {
    hash *= 31;
    hash += c - 'a' + 1;
  }
  return hash;
}

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> pref(n), revsuff(n);

  map<uint, vector<int>> hash_to_pref_inds, hash_to_revsuff_inds;
  for (int i = 0; i < n; i++) {
    cin >> pref[i] >> revsuff[i];
    reverse(revsuff[i].begin(), revsuff[i].end());
    hash_to_pref_inds[calc_hash(pref[i])].push_back(i);
    hash_to_revsuff_inds[calc_hash(revsuff[i])].push_back(i);
  }

  vector<int> marks(n, 0); // bool arrays are overrated, embrace marker arrays

  for (int curr_mark = 1; curr_mark <= m; curr_mark++) {
    string s;
    cin >> s;

    uint pref_hash = 0;

    for (char c : s) {
      pref_hash *= 31;
      pref_hash += c - 'a' + 1;
      for (int ind : hash_to_pref_inds[pref_hash]) {
        marks[ind] = curr_mark;
      }
    }
    reverse(s.begin(), s.end());
    uint revsuff_hash = 0;
    int cnt = 0;
    for (char c : s) {
      revsuff_hash *= 31;
      revsuff_hash += c - 'a' + 1;
      for (int ind : hash_to_revsuff_inds[revsuff_hash]) {
        if (marks[ind] == curr_mark && pref[ind].size() + revsuff[ind].size() <= s.size()) {
          cnt++;
        }
      }
    }
    cout << cnt << '\n';
  }
}
