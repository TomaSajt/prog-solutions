#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;

string f(int c) {
    string res = "";
    while (c >= 27) {
        c -= 1;
        int a = c % 26;
        c /= 26;
        res = (char)('A' + a) + res;
    }
    c -= 1;
    res = (char)('A' + c) + res;
    return res;
}
int g(string s) {
    //TODO
    int sum = 0;
    int mult = 1;
    for (int i = s.size() - 1;i >= 1;i--) {
        sum += mult * (s[i] - 'A');
        mult *= 26;
        mult++;
    }
    sum += mult * (s[0] - '@');
    return sum;
}

int main() {
    speed;
    for (int i = 1; i <= 1000; i++) {
        cout << i << " " << f(i) << " " << g(f(i)) << endl;
    }
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int i = 0;
        while (i < s.size() - 1 && !(s[i] <= '9' && s[i + 1] == 'C')) i++;
        if (i == s.size() - 1) {
            i = 0;
            while (i < s.size() - 1 && s[i] >= 'A' && s[i] <= 'Z') i++;
            cout << "R" << s.substr(i, s.size() - i) << "C" << g(s.substr(0, i)) << endl;
        }
        else {
            int r = stoi(s.substr(1, i));
            int c = stoi(s.substr(i + 2, s.size() - i - 1));
            cout << f(c) << r << endl;
        }

    }

}