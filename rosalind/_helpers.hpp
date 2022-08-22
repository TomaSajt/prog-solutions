#pragma once
#include <bits/stdc++.h>
using namespace std;

namespace rosalind {
    vector<pair<string, string>> getFasta(istream& stream);
}

ostream& operator<< (ostream& stream, const vector<int>& vec);