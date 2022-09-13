#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    set<string> sol;
    do sol.insert(s); while (next_permutation(s.begin(), s.end()));
    cout << sol.size() << '\n';
    for (auto& str : sol) cout << str << '\n';
}