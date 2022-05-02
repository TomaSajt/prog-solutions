#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;


struct thing {
    int y, x, v;
    bool operator<(thing other) {
        return v < other.v;
    }
};

int main() {
    speed;
    int n, m;
    cin >> n >> m;
    vector<thing> arr;
    for (int i = 0; i < n;i++) {
        for (int j = 0; j < m; j++) {
            int v;
            cin >> v;
            arr.push_back({ i,j,v });
        }
    }
    sort(arr.rbegin(), arr.rend());

    set<pair<int, int>> rowpairs;
    vector<vector<bool>> used(n, vector<bool>(m));

    for (auto& a : arr) {
        for (int j = 0;j < m;j++) {
            if (used[a.y][j]) {
                int r = a.x;
                int l = j;
                if (l > r)swap(r, l);
                if (rowpairs.find({ l,r }) != rowpairs.end()) {
                    cout << a.v << endl;
                    return 0;
                }
                else {
                    rowpairs.insert({ l,r });
                }
            }
        }
        used[a.y][a.x] = true;
    }

}