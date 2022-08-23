#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
vector<int> parents, sizes;
struct edge {
    int s, e, w;
};
int find_root(int a) {
    if (parents[a] == a) return a;
    return parents[a] = find_root(parents[a]);
}
void merge(int a, int b) {
    a = find_root(a);
    b = find_root(b);
    if (sizes[a] > sizes[b]) swap(a, b); // a will be shorter than b
    parents[a] = b;
    sizes[b] += sizes[a];
}
int main() {
    speed;
    int n, m;
    cin >> n >> m;
    parents.resize(n + 1);
    for (int i = 1; i <= n; i++) parents[i] = i;
    sizes.resize(n + 1, 1);
    vector<edge> edges(m);
    for (auto& edge : edges) cin >> edge.s >> edge.e >> edge.w;
    sort(edges.begin(), edges.end(), [](auto& a, auto& b) {return a.w < b.w;}); // növekvő sorrend
    int total = 0;
    for (auto [s, e, w] : edges) {
        if (find_root(s) != find_root(e)) {
            total += w;
            merge(s, e);
        }
    }
    cout << total << endl;

}