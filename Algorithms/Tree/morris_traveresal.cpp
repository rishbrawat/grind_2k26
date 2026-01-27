#include<bits/stdc++.h>
using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    TreeNode* curr = root;
    while (curr) {
        if (!curr->left) {
            res.push_back(curr->val);
            curr = curr->right;
        } else {
            // Find the inorder predecessor
            TreeNode* pre = curr->left;
            while (pre->right && pre->right != curr) {
                pre = pre->right;
            }
            // Create a temporary thread to the root
            if (!pre->right) {
                pre->right = curr;
                curr = curr->left;
            } else { // Thread already exists, remove it
                pre->right = nullptr;
                res.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return res;
}

