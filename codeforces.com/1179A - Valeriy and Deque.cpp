#include <bits/stdc++.h>
using namespace std;
//JÓ KÉPLET (szerintem) beallt_tomb[(kerdes - beallas_hossza) % (n-1) + 1]
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, iq;
    cin >> n >> iq;

    deque<int> q(n);
    int legnagyobb = -1;
    for (int& a : q) {
        cin >> a;
        if (a > legnagyobb) legnagyobb = a;
    }

    vector<pair<int, int>> allapotok; // beállás ideje = allapotok.size()
    while (q.front() != legnagyobb) {
        int a = q.front();
        q.pop_front();
        int b = q.front();
        q.pop_front();

        allapotok.push_back({ a, b });

        if (a > b) {
            q.push_front(a);
            q.push_back(b);
        }
        else {
            q.push_back(a);
            q.push_front(b);
        }
    }

    while (iq--) {
        long long kerdes;
        cin >> kerdes;

        if (kerdes <= allapotok.size()) { // 1-től indexel
            cout << allapotok[kerdes - 1].first << " " << allapotok[kerdes - 1].second << endl;
        }
        else {
            cout << legnagyobb << " " << q[(kerdes - allapotok.size() - 1) % (n - 1) + 1] << endl;
        }
    }
}