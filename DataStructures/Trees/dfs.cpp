#include<iostream>
#include<vector>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// preOrder: visit the root first, then visit all left child and then visit all right child
// data flows from top to bottom as the node is processed first and then its child are processed
void preOrderIterative(Node* root, vector<char>& result) {
    if(root == nullptr) return;


    vector<Node*> stack;

    stack.push_back(root);

    while(!stack.empty()) {
        Node* curr = stack.back();
        stack.pop_back();

        result.push_back(curr->data);

        if(curr->right){stack.push_back(curr->right);}
        if(curr->left){stack.push_back(curr->left);}
    }
}

void preOrderRecursive(Node* root, vector<char>& result) {
    // basec case: if the root is empty(nullptr) return
    if(!root) return;

    result.push_back(root->data);

    preOrderRecursive(root->left, result);
    preOrderRecursive(root->right, result);
}


// post order traversal: left->right->root
// process a node after its children are processed
// here the information flows from bottom to top, so also called bottom-up traversal
// ex- height of the tree, diameter of the tree, sizeof subtree, is tree balanced, mix path sum

void postOrderRecurisve(Node* root, vector<char>& result) {
    if(!root) return;

    // process the left child first
    postOrderRecurisve(root->left, result);
    postOrderRecurisve(root->right, result);
    result.push_back(root->data);
}

// inorder traversal: left->root->right
// useful for bst
// it produces sorted output
void inOrderRecursive(Node* root, vector<char>& result) {
    if(!root) return;
    postOrderRecurisve(root->left, result);
    result.push_back(root->data);
    postOrderRecurisve(root->right, result);
}

int main() {
    Node* root = new Node('a');
    Node* node2 = new Node('b');
    Node* node3 = new Node('c');
    Node* node4 = new Node('d');
    Node* node5 = new Node('e');

    root->left = node2;
    node2->left = node4;
    node2->right = node5;
    node4->left = node3;

    vector<char> result;
    preOrderIterative(root, result);

    for(auto c: result) {
        cout << c << ' ';
    } cout << endl;

    return 0;
}