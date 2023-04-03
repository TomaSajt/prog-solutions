// 68/100 - Task E is wrong




#include <bits/stdc++.h>
#define pb push_back
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<set<int>> gr(n + 1);
    int u, v;
    while ((cin >> u >> v) && u != 0) {
        gr[u].insert(v);
        gr[v].insert(u);
    }
    map<int, vector<int>> bands;
    vector<bool> vis(n + 1);
    for (int i = 1, id = 0; i <= n; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        if (gr[i].size() == 0) continue;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            bands[id].pb(curr);
            for (int nei : gr[curr]) {
                if (vis[nei]) continue;
                vis[nei] = true;
                q.push(nei);
            }
        }
        id++;
    }

    //A
    for (int i = 1; i <= n; i++) if (gr[i].size() == 0) cout << i << ' ';
    cout << '\n';

    //B
    cout << bands.size() << '\n';

    //C
    for (auto& [id, band] : bands) {
        int m = *max_element(band.begin(), band.end(), [&](int a, int b) {return gr[a].size() < gr[b].size();});
        cout << m << ' ';
    }
    cout << '\n';

    //D
    cout << max_element(bands.begin(), bands.end(), [&](auto& a, auto& b) {return a.second.size() < b.second.size();})->second.size() << '\n';

    //E
    for (auto& [id, band] : bands) {
        int m = *max_element(band.begin(), band.end(), [&](int a, int b) {return gr[a].size() < gr[b].size();});
        cout << m << ' ';
    }
    cout << '\n';

    //F
    int safes = 0;
    for (auto& [id, band] : bands) {
        bool safe = true;
        for (int& a : band) {
            if (gr[a].size() < 2) {
                safe = false;
                break;
            }
        }
        if (safe) safes++;
    }
    cout << safes << '\n';
    //G
    int risks = 0;
    for (auto& [id, band] : bands) {
        if (band.size() == 2) {
            risks++;
            continue;
        }
        int core = *find_if(band.begin(), band.end(), [&](int a) {return gr[a].size() != 1;});
        bool risk = true;
        for (int& a : band) {
            if (gr[a].size() != 1 && a != core) {
                risk = false;
                break;
            }
        }
        if (risk) risks++;
    }
    cout << risks << '\n';

    //H
    int stronks = 0;
    for (auto& [id, band] : bands) {
        bool stronk = true;
        stronk = true;
        for (int& a : band) {
            if (gr[a].size() != band.size() - 1) {
                stronk = false;
                break;
            }
        }
        if (stronk) stronks++;
    }
    cout << stronks << '\n';

}