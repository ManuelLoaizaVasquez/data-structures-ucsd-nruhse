#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long Long;
typedef pair<string, bool> Pair;

Long mod;
const Long prime = 1e9 + 7;
const Long base = 263;
vector<vector<Pair>> hash_table;

Long hash_function(const string &s) {
    int size_s = s.size();
    Long h = 0;
    Long x = 1;
    for (int i = 0; i < size_s; i++) {
        h = (h + s[i] * x) % prime;
        x  = (x * base) % prime;
    }
    h %= mod;
    return h;
}

bool find_string(const string &s) {
    Long hash_string = hash_function(s);
    Long size_list = hash_table[hash_string].size();
    for (int i = 0; i < size_list; i++) {
        if (hash_table[hash_string][i].second and hash_table[hash_string][i].first == s) return true;
    }
    return false;
}

void add_string(const string &s) {
    if (find_string(s)) return;
    Long hash_string = hash_function(s);
    hash_table[hash_string].push_back({s, true});
}

void delete_string(const string &s) {
    Long hash_string = hash_function(s);
    Long size_list = hash_table[hash_string].size();
    for (int i = 0; i < size_list; i++) {
        if (hash_table[hash_string][i].second and hash_table[hash_string][i].first == s) {
            hash_table[hash_string][i].second = false;
            return;
        }
    }
}

void check(Long hash_string) {
    bool first_time = true;
    Long size_list = hash_table[hash_string].size();
    for (int i = size_list - 1; i >= 0; i--) {
        if (hash_table[hash_string][i].second) {
            if (not first_time) cout << " ";
            first_time = false;
            cout << hash_table[hash_string][i].first;
        }
    }
    cout << endl;
}

int main() {
    fastio;
    cin >> mod;
    hash_table.resize(mod);
    Long queries;
    cin >> queries;
    while (queries--) {
        string type;
        cin >> type;
        if (type[0] == 'a') {
            string s;
            cin >> s;
            add_string(s);
        }
        if (type[0] == 'c') {
            Long position;
            cin >> position;
            check(position);
        }
        if (type[0] == 'f') {
            string s;
            cin >> s;
            if (find_string(s)) cout << "yes" << endl;
            else cout << "no" << endl;
        }
        if (type[0] == 'd') {
            string s;
            cin >> s;
            delete_string(s);
        }
    }
    return 0;
}