#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;

struct edge {
    int a, b, w, ind;
};
int parents[20001];
int sizes[20001];

int get_root(int a) {
    if (parents[a] == a) return a;
    return parents[a] = get_root(parents[a]);
}
void merge(int a, int b) {
    a = get_root(a);
    b = get_root(b);
    if (sizes[a] > sizes[b]) swap(a, b);
    parents[a] = b;
    sizes[b] += sizes[a];
}


int main() {
    speed;
    int n, m;
    cin >> n >> m;
    iota(parents, parents + n + 1, 0);
    fill(sizes, sizes + n + 1, 1);
    vector<edge> edges(m);
    for (int i = 0;i < m;i++) {
        edges[i].ind = i;
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
    }
    sort(edges.begin(), edges.end(), [](edge a, edge b) {return a.w > b.w;});
    int last;
    vector<int> v;
    for (auto& e : edges) {
        if (get_root(e.a) != get_root(e.b)) {
            merge(e.a, e.b);
            last = e.w;
            v.pb(e.ind);
        }
    }
    cout << last << endl;
    for (auto& i : v) cout << i + 1 << ' ';
    cout << endl;

}