#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef long long Long;
typedef pair<Long, Long> Pair;
const Long INF = 1e8;
bool ok = true;

struct Node {
  Long value;
  int left;
  int right;
};
vector<Node> graph;

Pair DFS(int u) {
  Long val = graph[u].value;
  int l = graph[u].left;
  int r = graph[u].right;
  Pair ans = {-1, -1};
  if (l != -1) {
    Pair left = DFS(l);
    if (not (left.first < val and left.second < val)) ok = false;
    ans = left;
  }
  if (r != -1) {
    Pair right = DFS(r);
    if (not (right.first > val and right.second > val)) ok = false;
    if (l != -1) {
      ans.second = right.second;
    } else {
      ans.first = val;
      ans.second = right.second;
    }
  } else {
    if (l != -1) ans.second = val;
  }
  if (l == -1 and r == -1) ans = {val, val};
  return ans;
}

int main() {
  fastio;
  int n;
  cin >> n;
  graph.resize(n);
  for (int i = 0; i < n; i++) cin >> graph[i].value >> graph[i].left >> graph[i].right;
  if (n == 0) {
    cout << "CORRECT" << endl;
    return 0;
  }
  DFS(0);
  if (ok) cout << "CORRECT" << endl;
  else cout << "INCORRECT" << endl;
  return 0;
}