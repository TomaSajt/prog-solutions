#include <bits/stdc++.h>
using namespace std;
#define speed    \
    cout.tie(0); \
    cin.tie(0);  \
    ios::sync_with_stdio(0)

int main()
{
    speed;
    int n;
    cin >> n;
    vector<int> val(n + 1);
    vector<int> ch(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        ch[a] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        val[i] = a;
    }
    int c = 1;
    vector<int> ord(n);
    for (int i = 0; i < n; i++)
    {
        ord[i] = c;
        c = ch[c];
    }
    int f = find_if(ord.begin(), ord.end(), [&](int i)
                    { return val[i] != -1; }) -
            ord.begin();

    int l = n - 1 - (find_if(ord.rbegin(), ord.rend(), [&](int i)
                             { return val[i] != -1; }) -
                     ord.rbegin());
    for (int i = f - 1; i >= 0; i--)
    {
        val[ord[i]] = val[ord[i + 1]] + 1;
    }
    for (int i = l + 1; i < n; i++)
    {
        val[ord[i]] = val[ord[i - 1]] + 1;
    }

    int last = f;
    int curr = f + 1;
    while (curr <= l)
    {
        if (val[ord[curr]] != -1)
        {
            if ((curr - last) < abs(val[ord[curr]] - val[ord[last]]))
            {
                cout << "NEM" << endl;
                exit(0);
            }
            if ((curr - last) % 2 != abs(val[ord[curr]] - val[ord[last]]) % 2)
            {
                cout << "NEM" << endl;
                exit(0);
            }
            int d = val[ord[curr]] - val[ord[last]] > 0 ? -1 : 1;
            if (val[ord[curr]] != val[ord[last]])
            {
                for (int i = curr - 1; (val[ord[i]] = val[ord[i + 1]] + d) != val[ord[last]]; i--)
                    ;
            }
            for (int i = last + 1; val[ord[i]] == -1; i++)
            {
                val[ord[i]] = val[ord[last]] + (i - last) % 2;
            }

            last = curr;
        }
        curr++;
    }

    cout << "IGEN" << endl;
    for (int i = 1; i <= n; i++)
        cout << val[i] << ' ';
    cout << endl;
}