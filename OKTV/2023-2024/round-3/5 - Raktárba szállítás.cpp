#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

int n, k, c;
int par[20001], cnt[20001];
vector<int> children[20001];
int branch_max[20001];

void dfs(int u) {
    branch_max[u]=cnt[u];
    for(int v : children[u]) {
        dfs(v);
        branch_max[u]=max(branch_max[u],branch_max[v]+cnt[u]);
    }
}

int decr(int u, int a) {
    int diff = min(cnt[u],a);
    cnt[u]-=diff;
    branch_max[u]=cnt[u];
    for(int v : children[u]) {
        branch_max[u]=max(branch_max[u],branch_max[v]+cnt[u]);
    }
    int rem = a-diff;
    if(par[u] == 0) return diff;
    return diff + decr(par[u],rem);
}

int descend(int u) {
    if(children[u].empty()) return u;
    for(int v : children[u]) {
        if(branch_max[v]+cnt[u] == branch_max[u]) {
            return descend(v);
        }
    }
    cout << "NOPE" << endl;
    return -1;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k >> c;

    for(int i = 1;i<=n; i++) {
        cin >> par[i] >> cnt[i];
        children[par[i]].push_back(i);
    }

    dfs(1);
    int res = 0;
    for(int i = 0; i<k;i++) {
        res+=decr(descend(1),c);
    }
    cout <<res;
}
