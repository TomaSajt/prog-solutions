#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int k;
    cin >> n;
    //k=2;
    cin >> k;
    vector<int> v(n+1);
    vector<int> DP(n+1,INT_MAX);
    for(int i=1; i<=n; i++)cin>>v[i];
    DP[1]=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=k; j++)
        {
            if(i-j<1) continue;
            DP[i]=min(DP[i],DP[i-j]+abs(v[i]-v[i-j]));
        }
    }
    cout << DP[n] << endl;
    return 0;
}

