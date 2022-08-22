#include "_helpers.hpp"

int counter = 1;

struct Node {
    int id = counter++;
    char ch = 0;
    vector<Node*> children;
};

ofstream out("C:/Users/Toma/Desktop/outttt.txt");

void constructTree(Node* parent, const vector<string>& strings) {
    map<char, vector<string>> charMap;
    for (auto& str : strings) {
        if (str.size() == 0) continue;
        charMap[str[0]].push_back(str.substr(1));
    }
    for (auto& [ch, substrings] : charMap) {
        Node* node = new Node;
        node->ch = ch;
        constructTree(node, substrings);
        parent->children.push_back(node);
    }
}

void logNode(Node* node) {
    for (auto& child : node->children) {
        out << node->id << ' ' << child->id << ' ' << child->ch << endl;
        logNode(child);
    }
}

int main() {
    string line;
    vector<string> strings;
    while (getline(cin, line)) strings.push_back(line);
    Node root;
    constructTree(&root, strings);
    logNode(&root);
}