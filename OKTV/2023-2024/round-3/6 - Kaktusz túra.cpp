// DOESN'T WORK
// 15/45 (trees only)

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = LLONG_MAX;
const int OFFSET=30000;


int n, m;
vector<vector<array<int,2>>> g,g2;

// id
vector<bool> vis;
stack<int> cycles_in_progress;
vector<int> vert_to_cycle;
int next_cid = 0;

void dfs(int u, int p) {
    vis[u]=1;
    for(auto [v,w] : g[u]) {
        if(v==p || vert_to_cycle[v] != -1) continue;
        if(vis[v]) {
            cycles_in_progress.push(next_cid++);
            vert_to_cycle[v]=cycles_in_progress.top();
        }
        else {
            dfs(v,u);
        }
        if(!cycles_in_progress.empty() && vert_to_cycle[v] == cycles_in_progress.top()) {
            if(vert_to_cycle[u]==vert_to_cycle[v]) {
                cycles_in_progress.pop();
            }
            else vert_to_cycle[u]=vert_to_cycle[v];
        }
    }
}

vector<int> dist;
void dfs2(int u) {
    for(auto [v,w] : g2[u]) {
        if(dist[v]!=-1) continue;
        dist[v]=dist[u]+w;
        dfs2(v);
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;

    g.resize(n+1);
    vis.resize(n+1,0);
    vert_to_cycle.resize(n+1,-1);
    for(int i = 0; i<m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    dfs(1,-1);

    /*
    for(int i = 1; i<=n;i++) {
        cout << vert_to_cycle[i] << ' ';
    }
    cout << endl;
    */

    g2.resize(OFFSET+next_cid);

    int non_cycle_len = 0;
    int cycle_len = 0;
    for(int u = 1; u<=n;u++) {
        int uu = vert_to_cycle[u] == -1 ? u : OFFSET+vert_to_cycle[u];
        for(auto [v,w] : g[u]) {
            int vv = vert_to_cycle[v] == -1 ? v : OFFSET+vert_to_cycle[v];
            if(uu == vv) {
                cycle_len+=w;
            }
            else {
                g2[uu].push_back({vv,w});
                non_cycle_len+=w;
            }
        }
    }

    /*
    for(int i = 1; i<g2.size();i++) {
        if(g2[i].empty()) continue;
        cout << i << " -> ";
        for(auto [v,w] : g2[i]) cout << v<< " ";
        cout << endl;
    }*/

    dist.resize(OFFSET+next_cid,-1);
    int start =  vert_to_cycle[1] == -1 ? 1 : OFFSET+vert_to_cycle[1];
    dist[start] = 0;
    dfs2(start);
    int high_cost_spine = *max_element(dist.begin()+1,dist.end());

    //cout << cycle_len/2 <<endl;
    //cout << non_cycle_len << endl;
    //cout << high_cost_spine <<endl;
    cout << cycle_len/2 + non_cycle_len; // - high_cost_spine;

}
