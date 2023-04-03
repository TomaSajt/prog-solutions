#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> s;
int main() {
    cin >> n >> m;
    for (int i = 0, a; i < n; i++) {
        float f;
        cin >> a >> f;
        auto it = upper_bound(s.begin(), s.end(), a);
        if (it == s.end()) s.push_back(a);
        else *it = a;
    }
    cout << n - s.size();
}