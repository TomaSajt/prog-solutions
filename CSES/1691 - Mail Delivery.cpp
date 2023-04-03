#include <bits/stdc++.h>
using namespace std;

vector<set<int>> graf;
vector<int> kor;

void keres(int akt) {
    vector<int> indit;
    while (!graf[akt].empty()) {
        int x = *graf[akt].begin();
        graf[akt].erase(x);
        graf[x].erase(akt);
        keres(x);
    }
    kor.push_back(akt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    graf.assign(n + 1, {});
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graf[a].insert(b);
        graf[b].insert(a);
    }
    for (int i = 1; i <= n; i++) {
        if (graf[i].size() % 2 != 0) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    keres(1);

    if ((int)kor.size() != m + 1) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for (int x : kor) {
        cout << x << " ";
    }
    cout << "\n";

}
