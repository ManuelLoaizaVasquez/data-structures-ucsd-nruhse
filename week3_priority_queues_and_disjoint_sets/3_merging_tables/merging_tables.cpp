#include <bits/stdc++.h>
using namespace std;

vector<int> rows;

struct DisjointSet {
	int size;
	vector<int> parent;
	vector<int> rank;
	DisjointSet(int n) {
		size = n;
		parent.resize(n);
		rank.resize(n);
	}

	void make_set(int i) {
		parent[i] = i;
		rank[i] = 0;
	}

	int find_set(int i) {
		if (i != parent[i]) parent[i] = find_set(parent[i]);
		return parent[i];
	}

	bool same_set(int i, int j) {
		return find_set(i) == find_set(j);
	}

	void union_set(int i, int j) {
		int id_i = find_set(i);
		int id_j = find_set(j);
		if (id_i == id_j) return;
		if (rank[id_i] < rank[id_j]) {
			parent[id_i] = id_j;
		} else {
			parent[id_j] = id_i;
			if (rank[id_i] == rank[id_j]) rank[id_i]++;
		}
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	rows.resize(n);
	for (int i = 0; i < n; i++) cin >> rows[i];
	DisjointSet dsu(n);
	for (int i = 0; i < n; i++) dsu.make_set(i);
	int max_size = 0;
	for (int i = 0; i < n; i++) max_size = max(max_size, rows[i]);
	while (m--) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		if (not dsu.same_set(u, v)) {
			int id_u = dsu.find_set(u);
			int id_v = dsu.find_set(v);
			int union_size = rows[id_u] + rows[id_v];
			rows[id_u] = rows[id_v] = 0;
			dsu.union_set(u, v);
			int id = dsu.find_set(u);
			rows[id] = union_size;
			max_size = max(max_size, union_size);
		}
		cout << max_size << endl;
	}
	return 0;
}
