#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
int main() {
    speed;
    int n, acc, cap, bat, pos = 0;
    cin >> n >> bat >> cap;
    acc = cap;
    vector<bool> lit(n);
    for (int i = 0, tmp; i < n; i++) {
        cin >> tmp;
        lit[i] = tmp == 1;
    }
    while ((acc || bat) && pos < n) {
        if (acc < cap && bat > 0 && lit[pos]) bat--, acc++;
        else if (acc > 0) acc--;
        else if (bat > 0) bat--;
        pos++;
    }
    cout << pos << endl;
}