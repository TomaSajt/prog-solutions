#include <bits/stdc++.h>
using namespace std;

bool is_digit(char c) { return c >= '0' && c <= '9'; }

bool is_letter(char c) { return c >= 'A' && c <= 'Z'; }

int f(const string& str) {
  int res = 0;
  for (auto&& c : str) {
    res *= 26;
    res += c - 'A' + 1;
  }
  return res;
}

string g(int i) {
  string str;
  while (i > 0) {
    int d = i % 26;
    i /= 26;
    if (d == 0) d = 26, i--;
    str = (char)('A' + d - 1) + str;
  }
  return str;
}

int main() {
  int n;
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  while (n--) {
    string str;
    cin >> str;
    auto fdit = find_if(str.begin(), str.end(), is_digit);
    auto cit = find_if(fdit, str.end(), is_letter);
    if (cit == str.end()) {
      int fdi = fdit - str.begin();
      string col = str.substr(0, fdi);
      int row = stoi(str.substr(fdi));
      cout << 'R' << row << 'C' << f(col) << endl;
    }
    else {
      int ci = cit - str.begin();
      int r = stoi(str.substr(1, ci - 1));
      int c = stoi(str.substr(ci + 1));
      cout << g(c) << r << endl;
    }
  }
}
