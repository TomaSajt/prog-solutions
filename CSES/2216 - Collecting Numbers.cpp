#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, c = 1;
    cin >> n;
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        pos[a] = i;
    }
    for (int i = 2; i <= n; i++) {
        if (pos[i - 1] > pos[i]) c++;
    }
    cout << c;
}