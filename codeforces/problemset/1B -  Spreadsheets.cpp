#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;
vector<int> zinds;

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

bool is_letter(char c) {
    return c >= 'A' && c <= 'Z';
}

int f(const string& str) {
    int extra = zinds[str.size() - 1];
    int curr = 0;
    for (auto& c : str) {
        curr *= 26;
        curr += c - 'A';
    }
    return curr + extra + 1;
}

string g(int i) {
    if (i == 1) return "A";
    auto lzit = find_if(zinds.rbegin(), zinds.rend(), [i](int zind) { return zind < i; });
    int size = zinds.size() - (lzit - zinds.rbegin());
    int lzind = *lzit;
    i -= lzind;
    i--;
    string s(size, 'A');
    int j = size - 1;
    while (i > 0) {
        s[j] = 'A' + (i % 26);
        i /= 26;
        j--;
    }
    return s;
}

int main(int n) {
    speed;
    cin >> n;
    string str;
    for (int i = 0, j = 1; i <= 1000000; j *= 26, i += j) zinds.push_back(i);
    while (cin >> str) {
        auto fdit = find_if(str.begin(), str.end(), is_digit);
        auto cit = find_if(fdit, str.end(), is_letter);
        if (cit == str.end()) {
            int fdi = fdit - str.begin();
            string col = str.substr(0, fdi);
            int row = stoi(str.substr(fdi));
            cout << 'R' << row << 'C' << f(col) << endl;
        }
        else {
            int ci = cit - str.begin();
            int r = stoi(str.substr(1, ci - 1));
            int c = stoi(str.substr(ci + 1));
            cout << g(c) << r << endl;
        }
    }

}