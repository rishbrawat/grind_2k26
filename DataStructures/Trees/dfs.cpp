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