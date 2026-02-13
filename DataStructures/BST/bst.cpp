/*
    each node in the tree is unique, the left subtree has values strictly less than the node (parent) and right subtree has values strictly graeter than the node(parent).

    - unique ordering of the elements (no duplicates allowed)
    - inorder traversal gives sorted order of elements
    - avg height o(log n, if balanced BST), worst case(O N)


    operations
    - insertion
    - deletion
    - search
    - traversal
*/

struct Node {
    int data;
    Node *left, *right;

    Node(int val): data(val), left(nullptr), right(nullptr) {};
};

#include<iostream>
#include<vector>
using namespace std;

class BST {
    Node* root;

    Node* insert(Node* node, int val) {

        if(!node) return new Node(val);

        if(val < node->data) {
            node->left = insert(node->left, val);
        }
        else if(val > node->data) {
            node->right = insert(node->right, val);
        }
        return node;
    }

    void inOrder(Node* node) {
        if(!node) return;

        inOrder(node->left);
        cout << node->data << ' ';
        inOrder(node->right);
    }

    bool search(Node* node, int val) {
        if(!node) return false;
        if(node->data == val) return true;

        return (val < node->data)? search(node->left, val) : search(node->right, val);
    }

    public:
        BST(): root(nullptr){};
        void insert(int val){root = insert(root, val);}
        void display() {inOrder(root); cout << endl;}
        bool find(int val) {return search(root, val);}
};



int  main() {
    BST tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(40);
    tree.insert(25);
    
    cout << "inorder traversal: ";
    tree.display();

    cout << "found 40 in the tree? " << boolalpha << tree.find(40) << endl;

    return 0;
}