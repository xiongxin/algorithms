#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <utility>

using namespace std;

class UnderflowException : public exception {
 public:
  UnderflowException() {}
};

template <typename Comparable>
struct BinaryNode {
  Comparable element;
  BinaryNode *left;
  BinaryNode *right;
  /*+*/ BinaryNode *parent; /*-*/

  BinaryNode(const Comparable &theElement, BinaryNode *lt, BinaryNode *rt,
             BinaryNode *par)
      : element{theElement}, left{lt}, right{rt}, parent{par} {}

  /*  BinaryNode( Comparable && theElement, BinaryNode *lt, BinaryNode *rt,
        BinaryNode *par)
: element{ std::move( theElement ) },
left{ lt }, right{ rt }, parent{ par } { } */
};

template <typename Comparable>
class BinarySearchTree {
 public:
  class BstIterator
      : public std::iterator<std::bidirectional_iterator_tag, Comparable> {
   public:
    BstIterator();

    // comparison operators. just compare node pointers
    bool operator==(const BstIterator &rhs) const;

    bool operator!=(const BstIterator &rhs) const;

    // dereference operator. return a reference to
    // the value pointed to by nodePtr
    const Comparable &operator*() const;

    // preincrement. move forward to next larger value
    BstIterator &operator++();

    // postincrement
    BstIterator operator++(int);

    // predecrement. move backward to largest value < current value
    BstIterator operator--();

    // postdecrement
    BstIterator operator--(int);

   private:
    friend class BinarySearchTree<Comparable>;

    // nodePtr is the current location in the tree. we can move
    // freely about the tree using left, right, and parent.
    // tree is the address of the stree object associated
    // with this iterator. it is used only to access the
    // root pointer, which is needed for ++ and --
    // when the iterator value is end()
    const BinaryNode<Comparable> *nodePtr;
    const BinarySearchTree<Comparable> *tree;

    // used to construct an iterator return value from
    // a node pointer
    BstIterator(const BinaryNode<Comparable> *p,
                const BinarySearchTree<Comparable> *t);
  };

  typedef BstIterator const_iterator;
  typedef const_iterator iterator;

  BinarySearchTree() : root{nullptr} {}

  /**
   * Copy constructor
   */
  BinarySearchTree(const BinarySearchTree &rhs) : root{nullptr} {
    root = clone(rhs.root);
  }

  /**
   * Move constructor
   */
  BinarySearchTree(BinarySearchTree &&rhs) : root{rhs.root} {
    rhs.root = nullptr;
  }

  /**
   * Destructor for the tree
   */
  ~BinarySearchTree() { makeEmpty(); }

  /**
   * Copy assignment
   */
  BinarySearchTree &operator=(const BinarySearchTree &rhs) {
    BinarySearchTree copy = rhs;
    std::swap(*this, copy);
    return *this;
  }

  /**
   * Move assignment
   */
  BinarySearchTree &operator=(BinarySearchTree &&rhs) {
    std::swap(root, rhs.root);
    return *this;
  }

  /**
search for item. if found, return an iterator pointing
at it in the tree; otherwise, return end()
   */
  const_iterator find(const Comparable &item) const;

  /**
   * return an iterator pointing to the first item (inorder)
   */
  const_iterator begin() const;

  /**
   * return an iterator pointing just past the end of
   * the tree data
   */
  const_iterator end() const;

  /**
   * Find the smallest item in the tree.
   * Throw UnderflowException if empty.
   */
  const Comparable &findMin() const {
    if (isEmpty()) throw UnderflowException{};
    return findMin(root)->element;
  }

  /**
   * Find the largest item in the tree.
   * Throw UnderflowException if empty.
   */
  const Comparable &findMax() const {
    if (isEmpty()) throw UnderflowException{};
    return findMax(root)->element;
  }

  /**
   * Returns true if x is found in the tree.
   */
  bool contains(const Comparable &x) const { return contains(x, root); }

  /**
   * Test if the tree is logically empty.
   * Return true if empty, false otherwise.
   */
  bool isEmpty() const { return root == nullptr; }

  /**
   * Print the tree contents in sorted order.
   */
  void printTree(ostream &out = cout) const {
    if (isEmpty())
      out << "Empty tree" << endl;
    else
      printTree(root, out);
  }

  /**
   * Make the tree logically empty.
   */
  void makeEmpty() { makeEmpty(root); }

  /**
   * Insert x into the tree; duplicates are ignored.
   */
  const_iterator insert(const Comparable &x) {
    auto t = insert(x, root, nullptr);
    if (t == nullptr)
      return end();
    else
      return const_iterator(t, this);
  }

  /**
   * Insert x into the tree; duplicates are ignored.
   */
  /*  void insert( Comparable && x )
{
insert( std::move( x ), root, nullptr );
}*/

  /**
   * Remove x from the tree. Nothing is done if x is not found.
   */
  void remove(const Comparable &x) { remove(x, root); }

 private:
  BinaryNode<Comparable> *root;

  /**
   * Internal method to insert into a subtree.
   * x is the item to insert.
   * t is the node that roots the subtree.
   * Set the new root of the subtree.
   */
  BinaryNode<Comparable> *insert(const Comparable &x,
                                 BinaryNode<Comparable> *&t,
                                 BinaryNode<Comparable> *par) {
    if (t == nullptr) {
      t = new BinaryNode<Comparable>{x, nullptr, nullptr, par};
      return t;
    } else if (x < t->element)
      return insert(x, t->left, t);
    else if (t->element < x)
      return insert(x, t->right, t);
    else
      return nullptr;  // Duplicate; do nothing
  }

  /**
   * Internal method to insert into a subtree.
   * x is the item to insert.
   * t is the node that roots the subtree.
   * Set the new root of the subtree.
   */
  /*  void insert( Comparable && x, BinaryNode<Comparable> * & t,
BinaryNode<Comparable> * par )
{
if( t == nullptr )
t = new BinaryNode<Comparable>{ std::move( x ), nullptr, nullptr, par};
else if( x < t->element )
insert( std::move( x ), t->left, t );
else if( t->element < x )
insert( std::move( x ), t->right, t );
else
;  // Duplicate; do nothing
}*/

  /**
   * Internal method to remove from a subtree.
   * x is the item to remove.
   * t is the node that roots the subtree.
   * Set the new root of the subtree. Return true if removed.
   */
  bool remove(const Comparable &x, BinaryNode<Comparable> *&t) {
    if (t == nullptr) return false;  // Item not found; do nothing
    if (x < t->element)
      return remove(x, t->left);
    else if (t->element < x)
      return remove(x, t->right);
    else if (t->left != nullptr && t->right != nullptr)  // Two children
    {
      t->element = findMin(t->right)->element;
      remove(t->element, t->right);
      return true;
    } else {
      BinaryNode<Comparable> *oldNode = t;
      t = (t->left != nullptr) ? t->left : t->right;
      delete oldNode;
      return true;
    }
  }

  /**
   * Internal method to find the smallest item in a subtree t.
   * Return node containing the smallest item.
   */
  BinaryNode<Comparable> *findMin(BinaryNode<Comparable> *t) const {
    if (t == nullptr) return nullptr;
    if (t->left == nullptr) return t;
    return findMin(t->left);
  }

  /**
   * Internal method to find the largest item in a subtree t.
   * Return node containing the largest item.
   */
  BinaryNode<Comparable> *findMax(BinaryNode<Comparable> *t) const {
    if (t != nullptr)
      while (t->right != nullptr) t = t->right;
    return t;
  }

  /**
   * Internal method to test if an item is in a subtree.
   * x is item to search for.
   * t is the node that roots the subtree.
   */
  bool contains(const Comparable &x, BinaryNode<Comparable> *t) const {
    if (t == nullptr)
      return false;
    else if (x < t->element)
      return contains(x, t->left);
    else if (t->element < x)
      return contains(x, t->right);
    else
      return true;  // Match
  }

  /**
   * Internal method to make subtree empty.
   */
  void makeEmpty(BinaryNode<Comparable> *&t) {
    if (t != nullptr) {
      makeEmpty(t->left);
      makeEmpty(t->right);
      delete t;
    }
    t = nullptr;
  }

  /**
   * Internal method to print a subtree rooted at t in sorted order.
   */
  void printTree(BinaryNode<Comparable> *t, ostream &out) const {
    if (t != nullptr) {
      printTree(t->left, out);
      out << t->element << endl;
      printTree(t->right, out);
    }
  }

  /**
   * Internal method to clone subtree.
   */
  BinaryNode<Comparable> *clone(BinaryNode<Comparable> *t) const {
    if (t == nullptr)
      return nullptr;
    else
      return new BinaryNode<Comparable>{t->element, clone(t->left),
                                        clone(t->right), t->parent};
  }
};

/**
   search for item. if found, return an iterator pointing
   at it in the tree; otherwise, return end()
 */
template <class Comparable>
typename BinarySearchTree<Comparable>::const_iterator
BinarySearchTree<Comparable>::find(const Comparable &item) const {
  auto t = root;
  while (t != nullptr && !(t->element == item)) {
    t = (item < t->element) ? t->left : t->right;
  }
  return BstIterator(t, this);
}

/**
 * return an iterator pointing to the first item (inorder)
 */
template <class Comparable>
typename BinarySearchTree<Comparable>::const_iterator
BinarySearchTree<Comparable>::begin() const {
  return BstIterator(findMin(root), this);
}

/**
 * return an iterator pointing just past the end of
 * the tree data
 */
template <class Comparable>
typename BinarySearchTree<Comparable>::const_iterator
BinarySearchTree<Comparable>::end() const {
  return BstIterator(nullptr, this);
}

template <class Comparable>
BinarySearchTree<Comparable>::BstIterator::BstIterator()
    : nodePtr(nullptr), tree(nullptr) {}

// comparison operators. just compare node pointers
template <class Comparable>
bool BinarySearchTree<Comparable>::BstIterator::operator==(
    const BstIterator &rhs) const {
  return tree == rhs.tree && nodePtr == rhs.nodePtr;
}

template <class Comparable>
bool BinarySearchTree<Comparable>::BstIterator::operator!=(
    const BstIterator &rhs) const {
  return tree != rhs.tree || nodePtr != rhs.nodePtr;
}

// dereference operator. return a reference to
// the value pointed to by nodePtr
template <class Comparable>
const Comparable &BinarySearchTree<Comparable>::BstIterator::operator*() const {
  if (nodePtr == nullptr) throw UnderflowException{};
  return nodePtr->element;
}

// preincrement. move forward to next larger value
template <class Comparable>
typename BinarySearchTree<Comparable>::BstIterator &
BinarySearchTree<Comparable>::BstIterator::operator++() {
  BinaryNode<Comparable> *p;

  if (nodePtr == nullptr) {
    // ++ from end(). get the root of the tree
    nodePtr = tree->root;

    // error! ++ requested for an empty tree
    if (nodePtr == nullptr) throw UnderflowException{};

    // move to the smallest value in the tree,
    // which is the first node inorder
    while (nodePtr->left != nullptr) {
      nodePtr = nodePtr->left;
    }
  } else if (nodePtr->right != nullptr) {
    // successor is the farthest left node of
    // right subtree
    nodePtr = nodePtr->right;

    while (nodePtr->left != nullptr) {
      nodePtr = nodePtr->left;
    }
  } else {
    // have already processed the left subtree, and
    // there is no right subtree. move up the tree,
    // looking for a parent for which nodePtr is a left child,
    // stopping if the parent becomes NULL. a non-NULL parent
    // is the successor. if parent is NULL, the original node
    // was the last node inorder, and its successor
    // is the end of the list
    p = nodePtr->parent;
    while (p != nullptr && nodePtr == p->right) {
      nodePtr = p;
      p = p->parent;
    }

    // if we were previously at the right-most node in
    // the tree, nodePtr = nullptr, and the iterator specifies
    // the end of the list
    nodePtr = p;
  }

  return *this;
}

// postincrement
template <class Comparable>
typename BinarySearchTree<Comparable>::BstIterator
BinarySearchTree<Comparable>::BstIterator::operator++(int) {
  auto saved = *this;
  operator++();
  return saved;
}

// predecrement. move backward to largest value < current value
template <class Comparable>
typename BinarySearchTree<Comparable>::BstIterator
BinarySearchTree<Comparable>::BstIterator::operator--() {
  BinaryNode<Comparable> *p;

  if (nodePtr == NULL) {
    // -- from end(). get the root of the tree
    nodePtr = tree->root;

    // error! -- requested for an empty tree
    if (nodePtr == NULL)
      throw UnderflowException("tree iterator operator--: tree empty");

    // move to the largest value in the tree,
    // which is the last node inorder
    while (nodePtr->right != NULL) nodePtr = nodePtr->right;
  } else if (nodePtr->left != NULL) {
    // must have gotten here by processing all the nodes
    // on the left branch. predecessor is the farthest
    // right node of the left subtree
    nodePtr = nodePtr->left;

    while (nodePtr->right != NULL) nodePtr = nodePtr->right;
  } else {
    //                    // must have gotten here by going right and then
    // far left. move up the tree, looking for a parent
    // for which nodePtr is a right child, stopping if the
    // parent becomes NULL. a non-NULL parent is the
    // predecessor. if parent is NULL, the original node
    // was the first node inorder, and its predecessor
    // is the end of the list
    p = nodePtr->parent;
    while (p != NULL && nodePtr == p->left) {
      nodePtr = p;
      p = p->parent;
    }

    // if we were previously at the left-most node in
    // the tree, nodePtr = NULL, and the iterator specifies
    // the end of the list
    !nodePtr = p;
  }

  return *this;
}

// postdecrement
template <class Comparable>
typename BinarySearchTree<Comparable>::BstIterator
BinarySearchTree<Comparable>::BstIterator::operator--(int) {
  auto saved = *this;
  operator--();
  return saved;
}

template <class Comparable>
BinarySearchTree<Comparable>::BstIterator::BstIterator(
    const BinaryNode<Comparable> *p, const BinarySearchTree<Comparable> *t)
    : nodePtr(p), tree(t) {}

#endif
