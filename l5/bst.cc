#include "utils.h"

template <typename DataType>
struct Node {
  Node(const DataType& e);
  static std::shared_ptr<Node> New(const DataType& e);
  DataType value;
  size_t size;
  //TODO: Add parent node
  std::shared_ptr<Node> left = nullptr;
  std::shared_ptr<Node> right = nullptr;
};

template <typename DataType>
Node<DataType>::Node(const DataType& e) : value(e), size(1) {}

template <typename DataType>
std::shared_ptr<Node<DataType>> Node<DataType>::New(const DataType& e) {
  return std::make_shared<Node<DataType>>(e);
}

template <typename DataType>
class BST {
  using NodePtr = std::shared_ptr<Node<DataType>>;
public:
  BST() = default;
  void Insert(const DataType& e);
  DataType Rank(const DataType& t) const { return 0; };

  void InorderPrint() const;
  void InorderPrint(const NodePtr& node, std::ostream* s) const;
private:

  NodePtr root_ = nullptr;

  void Insert(NodePtr* root, const NodePtr& node);
};

template <typename DataType>
void BST<DataType>::InorderPrint() const {
  std::ostringstream oss;
  InorderPrint(root_, &oss);
  puts(oss.str().c_str());
}

template <typename DataType>
void BST<DataType>::InorderPrint(const NodePtr& node, std::ostream* oss) const {
  if (!node) return;
  if (node->left) {
    InorderPrint(node->left, oss);
  }
  *oss << node->value << ',';
  if (node->right) {
    InorderPrint(node->right, oss);
  }
}

template <typename DataType>
void BST<DataType>::Insert(const DataType& e) {
  NodePtr node = Node<DataType>::New(e);
  Insert(&root_, node);
}

template <typename DataType>
void BST<DataType>::Insert(NodePtr* root, const NodePtr& node) {
  if (!(*root)) {
    *root = node;
    return;
  }
  ++(*root)->size;
  if (node->value < (*root)->value) {
    return Insert(&((*root)->left), node);
  }
  Insert(&((*root)->right), node);
}

int main() {
  BST<int> bst;
  for (int e : {8, 4, 10, 14, 3, 9, 16, 2, 7, 1}) bst.Insert(e);
  bst.InorderPrint();
  return 0;
}
