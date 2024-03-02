#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = LLONG_MAX;


signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> xa(n), xb(m);
    for(int& a : xa) cin >> a;
    for(int& b : xb) cin >> b;

    vector<array<int,4>> queries(k);
    for(int ind = 0; ind < k; ind++) {
        cin >> queries[ind][0] >> queries[ind][1];
        queries[ind][0]--;
        queries[ind][1]--;
        queries[ind][2] = ind;
    }
    sort(queries.rbegin(),queries.rend());

    vector<array<int,2>> dp_ip1(m+1,{-INF,-INF});
    vector<array<int,2>> dp_i(m+1,{-INF,-INF});

    int qi = 0;

    for(int i = n; i>=0; i--) {
        for(int j = m; j>=0; j--) {
            bool nf = i != n;
            bool mf = j != m;
            if(nf || mf) dp_i[j]={-INF,-INF};
            else dp_i[j] = {0,0};

            if(nf) {
                auto [next_opp, next_self] = dp_ip1[j];
                dp_i[j]=max(dp_i[j],{next_self+xa[i], next_opp});
            }
            if(mf) {
                auto [next_opp, next_self] = dp_i[j+1];
                dp_i[j]=max(dp_i[j],{next_self+xb[j], next_opp});
            }
            if(nf && mf) {
                auto [next_opp, next_self] = dp_ip1[j+1];
                dp_i[j]=max(dp_i[j],{next_self+xa[i]+xb[j], next_opp});
            }
            if(qi < k && queries[qi][0] == i && queries[qi][1] == j) {
                queries[qi][3]=dp_i[j][0];
                qi++;
            }
        }
        swap(dp_ip1,dp_i);
    }
    sort(queries.begin(),queries.end(), [](auto& a, auto& b){return a[2] < b[2]; });
    for(int i = 0; i<k;i++) {
        cout << queries[i][3] <<endl;
    }
}
