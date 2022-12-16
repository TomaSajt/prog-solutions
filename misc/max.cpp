#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) {
        int ap = (2 * a + 1) / (2 * a);
        int bp = (2 * b + 1) / (2 * b);
        int apbp = (ap + bp) / 2;
        int anbn = (2 - ap - bp) / 2;
        int apbn = (ap + 1 - bp) / 2;
        int anbp = (1 - ap + bp) / 2;
        int ab = a / b;
        int ba = b / a;
        int sa = ab / (ab + ba);
        int sb = ba / (ab + ba);
        int respp = sa * a + sb * b;
        int resnn = sb * a + sa * b;
        int res = apbp * respp + anbn * resnn + apbn * a + anbp * b;
        cout << res << endl;
    }
}