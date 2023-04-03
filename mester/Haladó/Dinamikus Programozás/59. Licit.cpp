//Code stolen


#include<bits/stdc++.h>

using namespace std;

const int N = 1003;

struct item{
    int bal, cost, id;
};

int n, m, dp[N];
array<int,2> p[N];
vector<item> bal[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        int l, r, c; cin >> l >> r >> c;
        bal[r].push_back({l, c, i});
    }

    fill(p, p+N, array<int,2>{-1,-1});
    array<int,2> mx = {-1 ,-1};

    for(int i = 1; i <= m; ++i){
        dp[i] = dp[i-1];
        p[i] = p[i-1];

        for(auto cur : bal[i]){
            if(dp[cur.bal-1] + cur.cost > dp[i]){
                dp[i] = dp[cur.bal-1] + cur.cost;
                p[i] = {cur.bal-1, cur.id};
            }
        }

        mx = max(mx, {dp[i], i});
    }

    int cur = mx[1];
    cout << mx[0] << '\n';
    while(p[cur][0] != -1){
        if(p[cur][1] != -1) cout << p[cur][1]+1 << ' ';
        cur = p[cur][0];
    }
    cout << '\n';


    return 0;
}
