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
    int goodNodes(TreeNode* root) {
        int count = 0;
        int max_val = INT_MIN;

        helper(root, count, max_val);
        return count;
    }

    void helper(TreeNode* root, int &count, int max_val) {
        if(root == NULL) {
            return;
        }

        if(root->val >= max_val) {
            max_val = root->val;
            count++; 
        }

        helper(root->left, count, max_val);
        helper(root->right, count, max_val);
    }
};