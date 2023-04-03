#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
vector<vector<int>> g;
vector<int> d, l;
set<int> res;
int t = 0;
int c = 0;

void dfs(int u) {
    d[u] = l[u] = ++t;
    for (auto v : g[u]) {
        if (d[v]) {
            // vissza-él logika
            // csak a d[v]-t nézzük az l[v] helyett, mert ezzel körbemegyünk felesleges egy körön
            l[u] = min(l[u], d[v]);
        }
        else {
            // fa-él logika
            // a kezdeti csúcsot külön kell kezelni, mert sosem lehet fölémenni
            // megszámoljuk a belőle kimenő fa-csúcsokat, és ha több mint 2, akkor elvágó
            if (u == 1) c++;
            dfs(v);
            l[u] = min(l[u], l[v]);
            if (u != 1 && d[u] <= l[v]) { // ha a gyerek minimum csak az u-ig tud visszajutni, akkor az u elvágó csúcs
                res.insert(u);
            }
        }
    }
}

int main() {
    speed;
    int n, m;
    while (cin >> n >> m && n) {
        t = 0;
        c = 0;
        g.assign(n + 1, {});
        d.assign(n + 1, 0);
        l.assign(n + 1, 0);
        res.clear();
        while (m--) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1);
        cout << res.size() + (c >= 2) << endl;
    }
}