

#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
using namespace std;

// This class is a template class that creates a binary
// tree that can hold values of any data type. It has
// functions to insert a node, delete a node, display the
// tree In Order, Pre Order and Post Order, search for a
// value, count the number of total nodes, left nodes,
// and a function to determine the height of the tree.

template <class T>
class BinaryTree
{
private:
    struct TreeNode
    {
        T value;            // The value in the node
        TreeNode *left;     // Pointer to left child node
        TreeNode *right;    // Pointer to right child node
    };

    TreeNode *root;         // Pointer to the root node

    // Private member functions
    void insert(TreeNode *&, TreeNode *&);
    void destroySubTree(TreeNode *);
    void deleteNode(T, TreeNode *&);
    void makeDeletion(TreeNode *&);
    void displayInOrder(TreeNode *);
    void inOrder(TreeNode *) ;
    //void displayPreOrder() const;
    void preOrder(TreeNode *);
    //void displayPostOrder() const;
    void postOrder(TreeNode *);
 
public:
    // Constructor
    BinaryTree()
    { root = NULL; }

    // Destructor
    ~BinaryTree()
    { destroySubTree(root); }

    // Binary tree operations
    void insertNode(T);
    bool searchNode(T);
    void remove(T);

    void displayPreOrder() const
    { preOrder(root); }

    void displayInOrder()
    { inOrder(root); }

    void displayPostOrder() const
    { postOrder(root); }

};

//*********************************************************
// insert function accepts a TreeNode pointer and a       *
// pointer to a node. The function inserts the node into  *
// the tree pointer to by the TreeNode pointer. This      *
// function is call recursively.                          *
//*********************************************************
template <class T>
void BinaryTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
    if (nodePtr == NULL)
        nodePtr = newNode;              // Insert the node
    else if (newNode->value < nodePtr->value)
        insert(nodePtr->left, newNode); // Search the left branch
    else
        insert(nodePtr->right, newNode);// Search the right branch
}

//*********************************************************
// insertNode creates a new node to hold item as its value*
// and passes it to the insert function.                  *
//*********************************************************
template <class T>
 void BinaryTree<T>::insertNode(T item)
 {
     TreeNode *newNode;     // Pointer to a new node

     // Create anew node and store num in it
     newNode = new TreeNode;
     newNode->value = item;
     newNode->left = newNode->right = NULL;

     // Insert the node
     insert(root, newNode);
 }

//**********************************************************
// destroySubTree is called by the destructor. It deletes  *
// all nodes in the tree.                                  *
//**********************************************************
template <class T>
void BinaryTree<T>::destroySubTree(TreeNode *nodePtr)
{
     if (nodePtr)
     {
         if (nodePtr->left)
             destroySubTree(nodePtr->left);
         if (nodePtr->right)
             destroySubTree(nodePtr->right);
         delete nodePtr;
     }
}

//**********************************************************
// searchNode determines if a value is present in the tree.*
// If so, the function returns true. Otherwise it returns  *
// false.
//**********************************************************
template <class T>
bool BinaryTree<T>::searchNode(T item)
{
    TreeNode *nodePtr = root;

    while (nodePtr)
    {
        if (nodePtr->value == item)
            return true;
        else if (item < nodePtr->value)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
    return false;
}

// Create a method inorder() to arrange the data in In-order transversal
template <class T>
void BinaryTree<T>::inOrder(TreeNode *nodePtr)
{
    if (nodePtr != NULL)
    {
        inOrder(nodePtr->left);
        cout << " " << &nodePtr->value << " ";
        inOrder(nodePtr->right);

       }

       else return;
}
#endif
