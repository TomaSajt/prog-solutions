#include <bits/stdc++.h>
using namespace std;

int parent[300001], sizes[300001], maxes[300001], mins[300001], rnk[300001];

int find_(int a) {
    return parent[a] != a ? parent[a] = find_(parent[a]) : a;
}
void union_(int a, int b) {
    a = find_(a), b = find_(b);
    if (a == b) return;
    if (rnk[a] < rnk[b]) swap(a, b);
    if (rnk[a] == rnk[b]) rnk[a]++;
    sizes[a] += sizes[b];
    parent[b] = a;
    mins[a] = min(mins[a], mins[b]);
    maxes[a] = max(maxes[a], maxes[b]);
}
int main() {
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);
    int n, m, a, b;
    string s;
    cin >> n >> m;
    iota(parent, parent + n + 1, 0);
    iota(maxes, maxes + n + 1, 0);
    iota(mins, mins + n + 1, 0);
    fill(sizes, sizes + n + 1, 1);
    fill(rnk, rnk + n + 1, 0);
    while (m--) {
        cin >> s;
        if (s[0] == 'u') {
            cin >> a >> b;
            union_(a, b);
        }
        else {
            cin >> a;
            a = find_(a);
            cout << mins[a] << ' ' << maxes[a] << ' ' << sizes[a] << '\n';
        }
    }
}