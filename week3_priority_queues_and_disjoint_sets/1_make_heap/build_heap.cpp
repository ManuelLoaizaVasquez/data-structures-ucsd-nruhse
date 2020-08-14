#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;
using std::min;
using std::max;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  int parent(int i) {
    return (i - 1) / 2;
  }

  int left_child(int i) {
    return 2 * i + 1;
  }

  int right_child(int i) {
    return 2 * i + 2;
  }

  void sift_down(int i) {
    int min_index = i;
    int l = left_child(i);
    if (l < data_.size() and data_[l] < data_[min_index]) {
      min_index = l;
    }
    int r = right_child(i);
    if (r < data_.size() and data_[r] < data_[min_index]) {
      min_index = r;
    }
    if (i != min_index) {
      swaps_.push_back({min(i, min_index), max(i, min_index)});
      swap(data_[i], data_[min_index]);
      sift_down(min_index);
    }
  }

  void GenerateSwaps() {
    swaps_.clear();
    for (int i = data_.size() / 2; i >= 0; i--) {
      sift_down(i);
    }
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
