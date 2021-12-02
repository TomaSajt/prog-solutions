#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, goldCount = 0, streakCount = 0;
    deque<bool> isGold(n);
    string s;
    cin >> n >> s;
    int pos = s.find('G');
    if (pos == string::npos)
    {
        cout << '0' << endl;
        return 0;
    }
    for (int i = pos; i < n; i++)
    {
        bool gold = s[i] == 'G';
        if (gold)
            goldCount++;
    }

}