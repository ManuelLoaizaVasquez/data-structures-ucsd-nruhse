#include <bits/stdc++.h>
using namespace std;

struct Bracket {
    char type;
    int position;
    Bracket(char type, int position):
        type(type),
        position(position)
    {}
    bool Match(char c) {
        if (type == '[' and c == ']') return true;
        if (type == '{' and c == '}') return true;
        if (type == '(' and c == ')') return true;
        return false;
    }
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    int mistake = -1;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            Bracket current(next, position);
            opening_brackets_stack.push(current);
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if (opening_brackets_stack.size() == 0) {
                mistake = position;
                break;
            } else {
                if (not opening_brackets_stack.top().Match(next)) {
                    mistake = position;
                    break;
                } else {
                    opening_brackets_stack.pop();
                }
            }
        }
    }

    // Printing answer, write your code here
    if (mistake == -1) {
        if (opening_brackets_stack.size() == 0) cout << "Success" << endl;
        else {
            mistake = opening_brackets_stack.top().position + 1;
            cout << mistake << endl;
        }
    } else {
        cout << mistake + 1 << endl;
    }
    return 0;
}
