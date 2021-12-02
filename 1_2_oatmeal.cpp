#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  string s;
  while (n--)
  {
    cin >> s;

    unordered_set<size_t>
        positions; // holds all the positions that sub occurs within str

    size_t pos = s.find("one", 0);
    while (pos != string::npos)
    {
      positions.insert(pos + 1);
      pos = s.find("one", pos + 3);
    }
    pos = s.find("two", 0);
    while (pos != string::npos)
    {
      positions.insert(pos + 3);
      pos = s.find("two", pos + 3);
    }
    cout << positions.size() << endl;
    if (positions.size())
    {
      for (auto &v : positions)
        cout << v << " ";
    }
    cout << endl;
  }
}
