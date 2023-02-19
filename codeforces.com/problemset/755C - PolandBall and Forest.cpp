#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n; cin >> n;
    vector<int> v;
    int alone = 0;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        if (i == a) alone++;
        else v.emplace_back(a);
    }
    sort(v.begin(), v.end());
    cout << (unique(v.begin(), v.end()) - v.begin()) / 2 + alone;
}


// Old solution with DSU

/*

#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

vector<int> sz, par;

int root(int a) {
    if (a == par[a]) return a;
    return par[a] = root(par[a]);
}

void merge(int a, int b) {
    a = root(a), b = root(b);
    if (sz[a] < sz[b]) swap(a, b);
    if (sz[a] == sz[b]) sz[a]++;
    par[b] = a;
}

int main() {
    speed;
    int n; cin >> n;
    sz.resize(n + 1, 1);
    par.resize(n + 1);
    iota(par.begin(), par.end(), 0);
    int cnt = n;
    for (int a = 1; a <= n; a++) {
        int b; cin >> b;
        if (root(a) != root(b)) {
            merge(a, b);
            cnt--;
        }
    }
    cout << cnt;
}

*/