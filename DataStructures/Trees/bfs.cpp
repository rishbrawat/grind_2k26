#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false);   cin.tie(nullptr);

/*
    bfs is levelOrder traversal where we visit from left to right in a level and then they move to the next level.

    first goes 
    level 1 root
    level 2 -root>left child root->right child
    level 3 left child->left child left child->right child , right child->left right child->right
    uses queue(fifo)

    use cases
    minimum depth of the tree
    closest leaf
    shortest path from the root
    level with maximum sum

    the first time we reach a node its the shortest path
*/
struct Node {
    int data;
    Node* left;
    Node* right;

    // constructor
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};


vector<vector<int>> bfs(Node* root) {
    vector<vector<int>> nums;
    if (!root) return nums;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();

            level.push_back(curr->data);

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        nums.push_back(level);
    }

    return nums;
}


int main() {
    fastio;

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<vector<int>> result = bfs(root);

    for (auto& level : result) {
        for (int x : level) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
