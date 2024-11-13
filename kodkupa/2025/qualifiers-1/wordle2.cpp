// 25/100

// NOTE: it is recommended to use this even if you don't understand
// the following code.

#include <iostream>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        string guess, response, answer = "zzzzz";
        int found = 0;
        for (char c = 'a'; c < 'z'; c++) {
            cout << "? " << c << c << c << c << c << endl;
            cin >> response;
            for (int i = 0; i < 5; i++) {
                if (response[i] == 'G') {
                    answer[i] = c;
                    found++;
                }
            }
            if (found == 5) break;
        }

        cout << "! " << answer << endl;
    }

    return 0;
}
