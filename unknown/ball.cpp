#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n;
    vector<int> boys(n);
    for (auto& i : boys)
        cin >> i;
    cin >> m;
    vector<int> girls(m);
    for (auto& i : girls)
        cin >> i;
    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());
    int i = 0, j = 0, c = 0;
    while (i < n && j < m) {
        int dif = boys[i] - girls[j];
        if (dif > 1)
            j++;
        else if (dif < -1)
            i++;
        else {
            i++;
            j++;
            c++;
        }
    }
    cout << c << endl;
}