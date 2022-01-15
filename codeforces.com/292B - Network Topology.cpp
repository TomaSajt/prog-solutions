#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n, m, c = -1;
    cin >> n >> m;
    vector<int> neighbourCount(n + 1);
    for (size_t i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        neighbourCount[a]++;
        neighbourCount[b]++;
    }
    for (size_t i = 1; i <= n; i++) {
        if (neighbourCount[i] >= 3) {
            if (c != -1) {
                cout << "unknown topology" << endl;
                return 0;
            }
            c = i;
        }
    }
    if (c != -1) {
        cout << (neighbourCount[c] == m ? "star topology" : "unknown topology") << endl;
        return 0;
    }
    cout << (n == m ? "ring topology" : "bus topology") << endl;

    return 0;
}
