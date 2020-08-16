#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
typedef long long Long;
using namespace std;
const int N = 1e7;

string phone_book[N];

int main() {
    fastio;
    for (int i = 0; i < N; i++) phone_book[i] = "#";
    int queries;
    cin >> queries;
    while (queries--) {
        string type;
        cin >> type;
        if (type[0] == 'a') {
            Long number;
            string name;
            cin >> number >> name;
            phone_book[number] = name;
        }
        if (type[0] == 'd') {
            Long number;
            cin >> number;
            phone_book[number] = "#";
        }
        if (type[0] == 'f') {
            Long number;
            cin >> number;
            if (phone_book[number].size() == 1 and phone_book[number][0] == '#') {
                cout << "not found" << endl;
            } else {
                cout << phone_book[number] << endl;
            }
        }
    }
    return 0;
}