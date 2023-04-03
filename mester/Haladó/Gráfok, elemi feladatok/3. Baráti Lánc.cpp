// 100/100
#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
const int start = 1;

vector<vector<bool>> g;
vector<bool> vis;
vector<int> cycle;
int n, k;


bool solve(int vertex) {
    vis[vertex] = 1;
    cycle.push_back(vertex);
    if (cycle.size() == n && g[vertex][start] == 1) return true;
    for (int i = 1; i <= n; i++)
        if (g[vertex][i] == 1 && vis[i] == 0)
            if (solve(i)) return true;
    vis[vertex] = 0;
    cycle.pop_back();
    return false;
}

int main() {
    speed;
    cin >> n >> k >> ws;
    g.resize(n + 1, vector<bool>(n + 1, 0));
    vis.resize(n + 1, 0);
    for (int i = 1;i <= n;i++) {
        string str;
        getline(cin, str);
        istringstream iss(str);
        int nei;
        while (iss >> nei) g[i][nei] = g[nei][i] = 1;
    }
    solve(start);
    for (int& i : cycle) cout << i << " ";
    cout << '\n';
}