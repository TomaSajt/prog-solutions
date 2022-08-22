#pragma once
#include <bits/stdc++.h>
using namespace std;

namespace rosalind {
    vector<pair<string, string>> getFasta(istream& stream) {
        vector<pair<string, string>> vec;
        while (!stream.eof()) {
            string line;
            getline(stream, line);
            string name = line.substr(1);
            string str = "";
            while (!stream.eof() && stream.peek() != '>') {
                getline(stream, line);
                str += line;
            }
            vec.push_back({ name,str });
        }
        return vec;
    }
}

ostream& operator<<(ostream& stream, const vector<int>& vec) {
    for (auto& i : vec) stream << i << ' ';
    return stream << endl;
}


template <typename T>
class counting_map {
    unordered_map<T, int> map;
public:
    void inc(const T& val) {
        map[val]++;
    }

    void dec(const T& val) {
        if (map.find(val) == map.end()) return;
        if (--map[val] == 0) map.erase(val);
    }

    int count_different() const {
        return map.size();
    }
};

class min_sliding_window {
    vector<int> values;
    deque<int> deque;
    int lo, hi;
public:
    min_sliding_window(const vector<int>& values, int start = 0) : values(values), lo(start), hi(start) {}

    void advance() {
        if (lo <= hi) {
            // delete all indices with value more than the value of the next index to be appended
            // this will make the deque monotonically increasing from front to back
            while (!deque.empty() && values[deque.back()] > values[hi]) deque.pop_back();
            deque.push_back(hi);
        }
        hi++;
    }
    void shrink() {
        if (!deque.empty() && deque.front() <= lo) deque.pop_front();
        lo++;
    }
    int curr_min() {
        if (lo >= hi) return INT_MAX;
        return values[deque.front()];
    }
};