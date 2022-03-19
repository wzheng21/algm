#include "utils.h"

template <typename DataType>
struct Node {
  Node(const DataType& e);
  static std::shared_ptr<Node> New(const DataType& e);
  DataType value;
  size_t node_size;
  std::weak_ptr<Node> parent = nullptr;
  std::shared_ptr<Node> left = nullptr;
  std::shared_ptr<Node> right = nullptr;
};

template <typename DataType>
Node<DataType>::Node(const DataType& e) : value(e), node_size(1) {}

template <typename DataType>
std::shared_ptr<Node<DataType>> Node<DataType>::New(const DataType& e) {
  return std::make_shared<Node<DataType>>(e);
}

template <typename DataType>
class BST {
public:
  BST() = default;
  void Insert(const DataType& e);
  DataType Rank(const DataType& t) const { return 0; };
private:
  using NodePtr = std::shared_ptr<Node<DataType>>;
  NodePtr root_ = nullptr;

  void Insert(NodePtr root, const DataType& e, const NodePtr& p = nullptr);
};

template <typename DataType>
void BST<DataType>::Insert(const DataType& e) {
  Insert(root_, e);
}

template <typename DataType>
void BST<DataType>::Insert(NodePtr root, const DataType& e, const NodePtr& p) {
  if (!root) {
    root.reset(Node<DataType>::New(e));
    return;
  }
  ++root->node_size;
  if (e < root->value) {
    if (!root->left) {
      Insert(root->left, e)
    }
  }
}

int main() {
  return 0;
}
