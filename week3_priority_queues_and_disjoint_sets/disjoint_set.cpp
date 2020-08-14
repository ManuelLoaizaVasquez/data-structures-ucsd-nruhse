#include <bits/stdc++.h>
using namespace std;

struct DisjointSet {
    int* parent;
    int* rank;
    int size;
    
    DisjointSet(int n) {
        size = n;
        parent = new int[n];
        rank = new int[n];
    }

    void make_set(int i) {
        parent[i] = i;
        rank[i] = 0;
    }

    int find_set(int i) {
        if (i != parent[i]) parent[i] = find_set(parent[i]);
        return parent[i];
    }

    void union_set(int i, int j) {
        int i_id = find_set(i);
        int j_id = find_set(j);
        if (i_id == j_id) return;
        if (rank[i_id] > rank[j_id]) {
            parent[j_id] = i_id;
        } else {
            parent[i_id] = j_id;
            if (rank[i_id] == rank[j_id]) {
                rank[j_id]++;
            }
        }
    }
};

int main() {
    DisjointSet dsu(12);
    for (int i = 0; i < 12; i++) dsu.make_set(i);
    dsu.union_set(1, 9);
    dsu.union_set(6, 4);
    dsu.union_set(5, 0);
    dsu.union_set(2, 3);
    dsu.union_set(4, 10);
    dsu.union_set(6, 7);
    dsu.union_set(6, 2);
    dsu.union_set(11, 1);
    dsu.union_set(8, 5);
    set<int> unique;
    for (int i = 0; i < 12; i++) {
        unique.insert(dsu.find_set(i));
    }
    int ans = 1;
    for (auto it = unique.begin(); it != unique.end(); it++) {
        int h = dsu.rank[*it];
        ans *= h;
    }
    cout << ans << endl;

    DisjointSet dsu2(61);
    for (int i = 1; i <= 60; i++) dsu2.make_set(i);
    for (int i = 1; i <= 30; i++) dsu2.union_set(i, 2 * i);
    for (int i = 1; i <= 20; i++) dsu2.union_set(i, 3 * i);
    for (int i = 1; i <= 12; i++) dsu2.union_set(i, 5 * i);
    unique.clear();
    for (int i = 1; i <= 60; i++) {
        int current_set = dsu2.find_set(i);
        unique.insert(current_set);
    }
    ans = 0;
    for (auto it = unique.begin(); it != unique.end(); it++) {
        ans = max(ans, dsu2.rank[*it]);
    }
    cout << ans << endl;
    return 0;
}