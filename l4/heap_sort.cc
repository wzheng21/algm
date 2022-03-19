#include "utils.h"

template <typename DataType, typename Compare>
class Heap {
public:
  Heap(std::vector<DataType>&& in);
  Heap() = default;
  void BuildHeap();
  void Pop();
  void Push(const DataType& e);
  const DataType& Top() const;
private:
  std::vector<DataType> data_;
  Compare comp_;
  void Heapify(int i);
};

template <typename DataType, typename Compare>
Heap<DataType, Compare>::Heap(std::vector<DataType>&& in) : data_(std::move(in)) {
  BuildHeap();
}

template <typename DataType, typename Compare>
void Heap<DataType, Compare>::BuildHeap() {
  for (int i = data_.size() / 2 - 1; i >= 0; --i) Heapify(i);
  std::cout << data_ << std::endl;
}

template <typename DataType, typename Compare>
const DataType& Heap<DataType, Compare>::Top() const {
  return data_.front();
}

template <typename DataType, typename Compare>
void Heap<DataType, Compare>::Pop() {
  std::swap(data_.front(), data_.back());
  data_.pop_back();
  Heapify(0);
}

template <typename DataType, typename Compare>
void Heap<DataType, Compare>::Heapify(int i) {
  if (i >= data_.size()) return;
  const int i_left = 2 * i + 1;
  if (i_left >= data_.size()) return;
  const int i_right = 2 * i + 2;
  bool comp_left_i = comp_(data_[i_left], data_[i]);
  if (i_right >= data_.size()) {
    if (!comp_left_i) return;
    std::swap(data_[i_left], data_[i]);
    return Heapify(i_left);
  }
  bool comp_right_i = comp_(data_[i_right], data_[i]);
  if (!comp_left_i && !comp_right_i) return;
  bool comp_left_right = comp_(data_[i_left], data_[i_right]);
  if (comp_left_right) {
    std::swap(data_[i_left], data_[i]);
    return Heapify(i_left);
  }
  std::swap(data_[i_right], data_[i]);
  Heapify(i_right);
}

template <typename DataType, typename Compare>
void Heap<DataType, Compare>::Push(const DataType& e) {
  data_.push_back(e);
  for (int j = data_.size() - 1; j > 0; j = (j - 1) / 2) {
    const int p = (j - 1) / 2;
    if (comp_(data_[p], data_[j])) break;
    std::swap(data_[p], data_[j]);
  }
}

int main() {
  Heap<int, std::greater<int>> max_heap({3, 4, 10, 14, 7, 9, 16, 2, 8, 1});
  std::cout << "Max heap: \n";
  std::cout << max_heap.Top();
  max_heap.Pop();
  for (int i = 1; i < 10; ++i) {
    std::cout << ", " << max_heap.Top();
    max_heap.Pop();
  }
  std::cout << "\n";

  Heap<int, std::less<int>> min_heap({3, 4, 10, 14, 7, 9, 16, 2, 8, 1});
  std::cout << "Min heap: \n";
  std::cout << min_heap.Top();
  min_heap.Pop();
  for (int i = 1; i < 10; ++i) {
    std::cout << ", " << min_heap.Top();
    min_heap.Pop();
  }
  std::cout << "\n";

  Heap<int, std::greater<int>> exp_heap;
  std::cout << "Exp heap max: ";
  for (int i : {3, 4, 10, 14, 7, 9, 16, 2, 8, 1}) {
    exp_heap.Push(i);
    std::cout << exp_heap.Top() << " ";
  }
  std::cout << '\n';
  std::cout << "Exp heap elements: \n";
  std::cout << exp_heap.Top();
  exp_heap.Pop();
  for (int i = 1; i < 10; ++i) {
    std::cout << ", " << exp_heap.Top();
    exp_heap.Pop();
  }
  std::cout << "\n";
  return 0;
}
