#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <stack>

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max_element;
using namespace std;

class StackWithMax {
    stack<int> original_stack;
    stack<int> max_stack;

public:
    void Push(int value) {
        original_stack.push(value);
        if (max_stack.empty()) max_stack.push(value);
        else max_stack.push(max(value, max_stack.top()));
    }

    void Pop() {
        assert(original_stack.size());
        assert(max_stack.size());
        original_stack.pop();
        max_stack.pop();
    }

    int Max() const {
        assert(original_stack.size());
        assert(max_stack.size());
        return max_stack.top();
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax current_stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            current_stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            current_stack.Pop();
        }
        else if (query == "max") {
            cout << current_stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}