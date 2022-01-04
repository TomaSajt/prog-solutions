#include <bits/stdc++.h>
using namespace std;
int main() {
    string str; cin >> str;
    vector<int> occurences(26);
    for (auto &ch : str) occurences[ch-'a']++;
    int a = 0;
    for (auto &i : occurences) {
        if(i%2==1) a++;
    }
    if(a==0) cout << "First" << endl;
    else cout << (a%2==1 ? "First" : "Second") << endl;
    
}