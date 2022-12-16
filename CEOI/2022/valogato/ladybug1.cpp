#include <bits/stdc++.h>
using namespace std;
#define speed    \
    cout.tie(0); \
    cin.tie(0);  \
    ios::sync_with_stdio(0)

vector<bool> vis;
vector<vector<int>> g;
vector<int> val;

void dfs(int u)
{
    vis[u] = true;
    for (int &v : g[u])
    {
        if (vis[v])
            continue;
        val[v] = val[u] + 1;
        dfs(v);
    }
}

int main()
{
    speed;
    int n;
    cin >> n;
    val.resize(n + 1);
    g.resize(n + 1);
    vis.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        g[a].push_back(i);
    }
    val[1] = 1;
    dfs(1);
    cout << "IGEN\n";
    for (int i = 1; i <= n; i++)
    {
        cout << val[i] << ' ';
    }
}