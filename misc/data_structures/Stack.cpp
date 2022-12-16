#include <bits/stdc++.h>
using namespace std;

struct Node {
    shared_ptr<Node> prev = shared_ptr<Node>(nullptr);
    int value;
    Node(int value) : value(value) {}
};

class Stack {
    shared_ptr<Node> top_ptr = shared_ptr<Node>(nullptr);
public:
    Stack& operator=(const Stack&) = delete;
    Stack(const Stack&) = delete;
    Stack() = default;
    void push(int value) {
        auto newNode = make_shared<Node>(value);
        newNode->prev = top_ptr;
        top_ptr = newNode;
    }
    int top() {
        if (top_ptr.get() == nullptr) throw runtime_error("hell naw");
        return top_ptr->value;
    }
    void pop() {
        if (top_ptr.get() == nullptr) throw runtime_error("hell naw");
        auto oldTop = top_ptr;
        top_ptr = top_ptr->prev;
    }

};

int main() {
    Stack stack;
    stack.push(100);
    stack.push(20);
    cout << stack.top() << endl;
    stack.pop();
    cout << stack.top() << endl;
    stack.pop();
    cout << stack.top() << endl;
    stack.pop();
    cout << stack.top() << endl;
    stack.pop();

}