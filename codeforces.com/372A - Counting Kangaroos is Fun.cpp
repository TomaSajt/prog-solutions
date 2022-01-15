#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& a : v) cin >> a;
    sort(v.begin(), v.end());
    int i, j, lathato = v.size();
    for (i = 0, j = v.size() / 2; i < v.size() / 2 && j < v.size(); i++) {
        for (; v[i] * 2 > v[j] && j < v.size(); j++);
        if (j < v.size()) {
            v[j] = 0;
            lathato--;
        }
    }
    cout << lathato << endl;
}