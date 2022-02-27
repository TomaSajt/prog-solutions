#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int i = 0;
map<int, int> parent;
map<int, int> sizes;
map<string, int> nti;
map<int, string> itn;

void create_(string name) {
    nti[name] = i;
    itn[i] = name;
    sizes[i] = 1;
    parent[i] = i;
    i++;
}
int find_(int i) {
    if (parent[i] == i) return i;
    return parent[i] = find_(parent[i]);
}
void union_(int a, int b) {
    a = find_(a);
    b = find_(b);
    if (a == b) return;
    if (sizes[a] < sizes[b]) swap(a, b);
    parent[b] = a;
    sizes[a] += sizes[b];

}
int size_(int i) {
    return sizes[find_(i)];
}
int main() {
    speed;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        i = 0, parent.clear(), sizes.clear(), nti.clear(), itn.clear();
        int m = n;
        while (m--) {
            string name1, name2;
            cin >> name1 >> name2;
            if (nti.find(name1) == nti.end()) create_(name1);
            if (nti.find(name2) == nti.end()) create_(name2);
            union_(nti[name1], nti[name2]);
            cout << size_(nti[name1]) << endl;
        }
    }
}