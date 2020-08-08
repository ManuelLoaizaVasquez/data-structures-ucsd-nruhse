#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif
using namespace std;

class Node {
public:
  int key;
  Node* parent;
  vector<Node*> children;
  
  Node() { this->parent = nullptr; }

  void setParent(Node* theParent) {
    parent = theParent;
    parent->children.push_back(this);
  }
};

int main_with_large_stack_space() {
  std::ios_base::sync_with_stdio(0);
  int n;
  cin >> n;

  vector<Node> nodes;
  nodes.resize(n);
  int root;
  for (int child_index = 0; child_index < n; child_index++) {
    int parent_index;
    cin >> parent_index;
    if (parent_index >= 0) {
      nodes[child_index].setParent(&nodes[parent_index]);
    } else {
      root = child_index;
    }
    nodes[child_index].key = child_index;
  }

  // Replace this code with a faster implementation
  int maxHeight = 1;
  vector<int> heights;
  heights.resize(n);
  stack<int> traversal;
  traversal.push(root);
  while (not traversal.empty()) {
    int current_index = traversal.top();
    traversal.pop();
    Node current = nodes[current_index];
    if (current.parent == nullptr) heights[current_index] = 1;
    else heights[current.key] = heights[current.parent->key] + 1;
    maxHeight = max(maxHeight, heights[current.key]);
    for (Node* child : current.children) traversal.push(child->key);
  }
  cout << maxHeight << endl;
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }

#endif
  return main_with_large_stack_space();
}
