#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;

int main() {
    speed;
    int n, m, a, c;
    map<int, int> counts;
    cin >> n;
    while (n--) {
        cin >> m;
        counts.clear();
        c = 0;
        for (int i = 0; i < m; i++) {
            cin >> a;
            a=abs(a);
            if(counts[a] < 2) c++;
            counts[a]++;
        }
        cout << c-(counts[0] >= 2) << endl;
    }
}