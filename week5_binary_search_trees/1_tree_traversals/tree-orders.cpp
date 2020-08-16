#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef long long Long;

struct Node {
  Long value;
  Long left;
  Long right;
};

vector<Node> graph;
vector<Long> in_order, pre_order, post_order;

void in_order_traversal(int u) {
  int l = graph[u].left;
  int r = graph[u].right;
  Long val = graph[u].value;
  if (l != -1) in_order_traversal(l);
  in_order.push_back(val);
  if (r != -1) in_order_traversal(r);
}

void pre_order_traversal(int u) {
  int l = graph[u].left;
  int r = graph[u].right;
  Long val = graph[u].value;
  pre_order.push_back(val);
  if (l != -1) pre_order_traversal(l);
  if (r != -1) pre_order_traversal(r);
}

void post_order_traversal(int u) {
  int l = graph[u].left;
  int r = graph[u].right;
  Long val = graph[u].value;
  if (l != -1) post_order_traversal(l);
  if (r != -1) post_order_traversal(r);
  post_order.push_back(val);
}

void print(vector<Long>& v) {
  int size_v = v.size();
  for (int i = 0; i < size_v; i++) {
    if (i > 0) cout << " ";
    cout << v[i];
  }
  cout << endl;
}

int main() {
  fastio;
  Long n;
  cin >> n;
  graph.resize(n);
  for (int i = 0; i < n; i++) cin >> graph[i].value >> graph[i].left >> graph[i].right;
  in_order_traversal(0);
  pre_order_traversal(0);
  post_order_traversal(0);
  print(in_order);
  print(pre_order);
  print(post_order);
  return 0;
}