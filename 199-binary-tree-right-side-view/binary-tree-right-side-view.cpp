/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>res;
    vector<int> rightSideView(TreeNode* root) {
      helper(root, 0);
      return res;  
    }

    void helper(TreeNode* root, int depth) {
        if(root == NULL) return;

        if(res.size() == depth) {
            res.push_back(root->val);
        }

        helper(root->right, depth + 1);
        helper(root->left, depth + 1);

    }
};