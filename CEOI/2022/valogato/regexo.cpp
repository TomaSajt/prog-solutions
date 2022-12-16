#include <bits/stdc++.h>
using namespace std;
#define speed    \
    cout.tie(0); \
    cin.tie(0);  \
    ios::sync_with_stdio(0)

int main()
{
    speed;
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        vector<int> a('z' + 1);
        vector<int> b('z' + 1);
        for (char &c : s1)
            a[c]++;
        for (char &c : s2)
            b[c]++;
        int s = 0;
        for (char c = 'A'; c <= 'Z'; c++)
        {
            if (a[c] == b[c])
                s += b[c];
            else
            {
                
            }
        }
    }
}