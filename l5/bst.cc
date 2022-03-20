#include "utils.h"

template <typename DataType>
struct Node {
  Node(const DataType& e);
  static std::shared_ptr<Node> New(const DataType& e);
  DataType value;
  size_t size;
  std::weak_ptr<Node> parent;
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
  int Rank(const DataType& t) const;

  void InorderPrint() const;
  void InorderPrint(const NodePtr& node, std::ostream* s) const;
private:

  NodePtr root_ = nullptr;

  void Insert(NodePtr* root, NodePtr* node, const NodePtr& p);
  std::shared_ptr<Node<DataType>> FindMinMax(const NodePtr& root, const DataType& e) const;
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
  *oss << node->value << '(' << node->size << "),";
  if (node->right) {
    InorderPrint(node->right, oss);
  }
}

template <typename DataType>
void BST<DataType>::Insert(const DataType& e) {
  NodePtr node = Node<DataType>::New(e);
  Insert(&root_, &node, nullptr);
}

template <typename DataType>
void BST<DataType>::Insert(NodePtr* root, NodePtr* node, const NodePtr& p) {
  if (!(*root)) {
    *root = *node;
    (*node)->parent = p;
#ifdef DEBUG
    std::cout << "Node: " << (*node)->value;
    if ((*node)->parent.use_count() > 0) {
      std::cout << ", parent: " << p->value;
    }
    std::cout << std::endl;
#endif
    return;
  }
  ++(*root)->size;
  if ((*node)->value < (*root)->value) {
    return Insert(&((*root)->left), node, *root);
  }
  Insert(&((*root)->right), node, *root);
}

template <typename DataType>
std::shared_ptr<Node<DataType>> BST<DataType>::FindMinMax(const NodePtr& root, const DataType& e) const {
  if (!root) return nullptr;
  if (e <= root->value) return FindMinMax(root->right, e);
  if (!root->left) return root;
  return FindMinMax(root->left, e);
}

template <typename DataType>
int BST<DataType>::Rank(const DataType& e) const {
  NodePtr node = FindMinMax(root_, e);
  if (!node) return root_->size;
  return root_->size - node->size;
}

int main() {
  BST<int> bst;
  for (int e : {8, 4, 10, 14, 3, 9, 16, 2, 7, 1}) bst.Insert(e);
  bst.InorderPrint();
  std::cout << "Rank of 17: " << bst.Rank(17) << std::endl;
  std::cout << "Rank of 16: " << bst.Rank(16) << std::endl;
  std::cout << "Rank of 15: " << bst.Rank(15) << std::endl;
  return 0;
}
