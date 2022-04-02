#include <bits/stdc++.h>
using namespace std;
#define speed    \
    cout.tie(0); \
    cin.tie(0);   \
    ios::sync_with_stdio(0)

int main()
{
    speed;
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int t, a, b;
        cin >> t >> a >> b;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << ' ' << 2 * n - i + 1 << endl;
    }
}

/*
vector<int> befok;
vector<bool> vis;
vector<vector<int>> g;
vector<int> order;

vector<pair<int, int>> inters;

void dfs(int u)
{
    order.push_back(u);
    vis[u] = true;
    for (int v : g[u])
    {
        befok[v]--;
        if (!vis[v] && befok[v] == 0)
        {
            dfs(v);
        }
    }
}

int veg(int a)
{
    return 2 * a + 1;
}
int kezd(int a)
{
    return 2 * a;
}
int main()
{
    speed;
    int n, m;
    cin >> n >> m;
    g.resize(2 * (n + 1));
    vis.resize(2 * (n + 1));
    befok.resize(2 * (n + 1));
    inters.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        g[kezd(i)].push_back(veg(i));
        befok[veg(i)]++;
    }
    while (m--)
    {
        int t, a, b;
        cin >> t >> a >> b;
        if (a > b)
            swap(a, b);
        if (t == 1)
        {
            g[kezd(a)].push_back(veg(b));
            g[kezd(b)].push_back(veg(a));
            befok[veg(b)]++;
            befok[veg(a)]++;
        }
        else
        {
            g[veg(a)].push_back(kezd(b));
            befok[kezd(b)]++;
        }
    }
    for (int i = 2; i <= 2 * n + 1; i++)
    {
        if (!vis[i] && befok[i] == 0)
            dfs(i);
    }
    for (int i = 2; i <= 2 * n + 1; i++)
    {
        if (befok[i] != 0)
        {
            cout << "NEM" << endl;
            return 0;
        }
    }
    for (int i = 1; i <= order.size(); i++)
    {
        int curr = order[i - 1];
        if (curr % 2 == 0)
        {
            inters[curr / 2].first = i;
        }
        else
        {
            inters[curr / 2].second = i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << inters[i].first << ' ' << inters[i].second << endl;
    }
}*/