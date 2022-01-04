#include <bits/stdc++.h>
using namespace std;

vector<bool> visited(26);
vector<unordered_set<int>> graph(26);
stack<int> s;
vector<int> tsort;
void dfs(int u) {
    visited[u] = true;

    for (auto it : graph[u]) {
        if (!visited[it])
            dfs(it);
    }
    s.push(u);
}
bool check_cycle() {
    unordered_map<int, int> pos;
    int ind = 0;
    while (!s.empty()) {
        pos[s.top()] = ind;
        tsort.push_back(s.top());
        ind += 1;
        s.pop();
    }

    for (int i = 0; i < 26; i++) {
        for (auto it : graph[i]) {
            if (pos[i] > pos[it]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    string prev, curr;
    cin >> prev;
    for (int j = 1; j < n; j++) {
        cin >> curr;
        int minSize = min(curr.size(), prev.size());
        for (int i = 0; i < minSize; i++) {
            if (prev[i] != curr[i]) {
                graph[prev[i] - 'a'].insert(curr[i] - 'a');
                break;
            }
            if (i == minSize - 1 && curr.size() < prev.size()) {
                cout << "Impossible" << endl;
                return 0;
            }
        }
        prev = curr;
    }

    for (int i = 0; i < 26; i++) {
        if (visited[i] == 0) {
            dfs(i);
        }
    }
    if (check_cycle())
        cout << "Impossible";
    else
        for (auto& i : tsort)
            cout << (char)(i + 'a');

    cout << endl;
    return 0;
}