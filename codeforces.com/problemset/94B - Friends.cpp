#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
bool adj[6][6];
int main() {
    speed;
    int a, b;
    cin >> a;
    while (cin >> a >> b) adj[a][b] = adj[b][a] = 1;
    for (int i = 1; i <= 5; i++) {
        for (int j = i + 1; j <= 5; j++) {
            for (int k = j + 1; k <= 5; k++) {
                if (adj[i][j] == adj[j][k] && adj[i][j] == adj[i][k] && adj[j][k] == adj[i][k]) {
                    cout << "WIN";
                    return 0;
                }
            }
        }
    }
    cout << "FAIL";
    return 0;
}
