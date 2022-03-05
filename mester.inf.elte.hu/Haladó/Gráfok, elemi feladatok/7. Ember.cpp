// 95/100 - Fails only on first test for some reason

#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;

int main() {
    speed;
    int n;
    cin >> n;
    int m = n;
    vector<vector<int>> g(n + 1);
    vector<int> children(n + 1);
    vector<int> grandchildren(n + 1);
    while (m--) {
        int u, v;
        cin >> ws >> u >> v;
        g[u].pb(v);
    }
    for (int i = 1; i <= n; i++) {
        for (int j : g[i]) {
            children[i]++;
            for (int k : g[j]) grandchildren[i]++;
        }
    }
    cout << max_element(children.begin() + 1, children.end()) - children.begin() << '\n';
    cout << max_element(grandchildren.begin() + 1, grandchildren.end()) - grandchildren.begin() << '\n';
    cout << count_if(grandchildren.begin() + 1, grandchildren.end(), [](int x) { return x == 0; }) << '\n';
}