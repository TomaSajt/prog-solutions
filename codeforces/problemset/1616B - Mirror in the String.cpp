#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;

int main() {
    speed;
    int n, m;
    string l;
    cin >> n;
    while (n--) {
        cin >> m >> l;
        int ind = 0;
        for (;ind < m - 1 && ((l[0] == l[ind] && l[ind] > l[ind + 1]) || (l[0] != l[ind] && l[ind] >= l[ind + 1]));ind++);
        for (int i = 0;i <= ind;i++) cout << l[i];
        for (int i = ind;i >= 0;i--) cout << l[i];
        cout << endl;
    }
}