#include <iostream>
using namespace std;
int main()     {
    long long x, k, A, B, c = 0;
    cin >> x >> k >> A >> B;
    while (x > 1)         {
        long long r = x % k;
        x -= r;
        c += r * A;
        if (A * x * (k - 1) <= B * k)
            break;
        x /= k;
        c += B;
    }
    c += x * A;
    c -= A;
    cout << c;
}