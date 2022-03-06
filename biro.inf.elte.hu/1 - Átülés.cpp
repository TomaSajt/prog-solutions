#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;

vector<int> a;
vector<bool> v;
int main() {
    speed;
    int n;
    cin >> n;
    a.resize(n + 1), v.resize(n + 1);
    for (int i = 1;i <= n;i++) cin >> a[i];
    int r = n;
    for (int i = 1;i <= n;i++) {
        if (v[i]) continue;
        if (i == a[i]) {
            r--;
            continue;
        }
        int j = i;
        do {
            v[j] = 1;
            j = a[j];
        } while (j != i);
        r++;
    }
    cout << r << endl;
}