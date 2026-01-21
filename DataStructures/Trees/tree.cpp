/*
    tree stores data in nodes which is simiilar to the linked lists
    the first node is called root

    -each node has variable number of references to the children/successor
    -each node (except root) has exactly one node as its predecessor


    the data is hierarchial

                a
            c       d
          e   f   g   h

        

    all nodes has 0 or more child nodes 
    for all nodes except root, has 1 parent node
    the degree of a node is its number of children

    -nodes with 0 degree are called leaf nodes
    - all other nodes are said to be internal nodes, that is they are internal to the tree
    - for each node in the tree there exists a unique path from the root node to that node
    - the length of this path is called depth of the node
    - the height of the tree is defined as the maximum depth from the root 
    - the height of a tree with one node is 0 (only root)

    - if a path exists from a to b
        - a is ancestor of b
        - b is descendant of a


    - tree as abstract dt
    generic methods:
        size
        isempty
        elements
        positions

        root
        parent
        children

        isInternal
        isLeaf
        isRoot


        swap
        replaceElement
        

*/

#include<iostream>
#include<vector>
using namespace std;

class TreeNode {
    public:
        int data;
        vector<TreeNode*> children;

    TreeNode(int val) {
        data = val;
    }
};

void printTree(TreeNode* root, int level = 0) {
    if(root == nullptr) {
        return;
    }
    for(int i = 0; i < level; ++i) {
        cout << " ";
    }
    cout << root->data << endl;

    for(TreeNode* child: root->children) {
        printTree(child, level+1);
    }
}


int main() {
    TreeNode* root = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);


    root->children.push_back(node2);
    root->children.push_back(node3);

    printTree(root);
}   