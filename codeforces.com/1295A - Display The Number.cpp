#include <iostream>
using namespace std;
void test();
int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) test();
    return 0;
}
void test() {
    int n; cin >> n;
    string res;
    if (n % 2 == 0) {
        res = string(n / 2, '1');
    }
    else {
        res = string(n / 2 - 1, '1');
        cout << "7";
    }
    cout << res << endl;
}