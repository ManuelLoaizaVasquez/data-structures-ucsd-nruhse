#include <bits/stdc++.h>
using namespace std;
typedef long long Long;

const int MOD = 8;

struct Log {
    Long ip[4];
    Long cnt;
    Log() {}
    Log(Long _ip[], Long _cnt) {
        for (int i = 0; i < 4; i++) ip[i] = _ip[i];
        cnt = _cnt;
    }
};
vector<Log> hash_table[MOD];

Long h(Long ip[]) {
    return 0;
}

bool equal_ip(Long ip_1[], Long ip_2[]) {
    for (int i = 0; i < 4; i++) {
        if (ip_1[i] != ip_2[i]) return false;
    }
    return true;
}

bool has_key(Long ip[]) {
    vector<Log>& current_row = hash_table[h(ip)];
    int size_row = current_row.size();
    for (int pos = 0; pos < size_row; pos++) {
        if (equal_ip(ip, current_row[pos].ip)) return true;
    }
    return false;
}

Long get(Long ip[]) {
    vector<Log>& current_row = hash_table[h(ip)];
    int size_row = current_row.size();
    for (int pos = 0; pos < size_row; pos++) {
        if (equal_ip(ip, current_row[pos].ip)) return current_row[pos].cnt;
    }
    return -1;
}

void set(Long ip[], Long value) {
    vector<Log>& current_row = hash_table[h(ip)];
    int size_row = current_row.size();
    for (int pos = 0; pos < size_row; pos++) {
        if (equal_ip(ip, current_row[pos].ip)) {
            current_row[pos].cnt = value;
            return;
        }
    }
    current_row.push_back(Log(ip, value));
}

int main() {
    return 0;
}