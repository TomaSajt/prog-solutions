#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(int a) {
    for (cin >> a; cin >> a;) {
        auto it = lower_bound(v.begin(), v.end(), a);
        if (it == v.end()) v.push_back(a);
        else *it = a;
    }
    cout << v.size();
}