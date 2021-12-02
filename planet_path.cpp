#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;

int main() {
    speed;
    int n, k, s;
    cin >> n >> k >> s;
    vector<vector<pair<int, int>>> g(k + 1);
    vector<int> A(n + 1);
    vector<vector<int>> C(n + 1, vector<int>(k + 1));
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) for (int j = 0; j < k; j++) cin >> C[i][j];






}