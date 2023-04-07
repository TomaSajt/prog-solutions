#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

typedef bitset<501> num;
num neg1(0), pos1(1);

num mult2(const num& inp) {
    num res;
    for (int i = 0; i < 500; i++) {
        res[i + 1] = inp[i];
    }
    return res;
}

num div2(const num& inp) {
    num res;
    for (int i = 0; i < 500; i++) {
        res[i] = inp[i + 1];
    }
    return res;
}

num add(const num& a, const num& b) {
    num res;
    for (int i = 0, cry = 0; i <= 500; i++) {
        int d = cry + a[i] + b[i];
        res[i] = d % 2;
        cry = (d / 2);
    }
    return res;
}

int main() {
    speed;
    for (int i = 0; i <= 500; i++) neg1[i] = 1;
    num a;
    int r = 0;
    int n; cin >> n;
    while (n--) {
        int o; cin >> o;
        if (o == 0) a = mult2(a), r++;
        else if (o == 1) a = add(mult2(a), pos1), r++;
        else if (o == 2) a = div2(a), r--;
        else if (o == 3) a = add(a, neg1);
        else if (o == 4) a = add(a, pos1);
    }
    cout << r << endl;
    int i = 500;
    for (; i >= 0 && !a[i]; i--);
    if (i == -1) cout << 0;
    for (; i >= 0; i--) cout << a[i];
}