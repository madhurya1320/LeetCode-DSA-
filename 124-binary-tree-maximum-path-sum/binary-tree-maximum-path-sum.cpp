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
    int maxPathSum(TreeNode* root) {
       int res = root->val;
       helper(root, res);
       return res;

    }
    int helper(TreeNode* root, int &res) {
    if(root == NULL) {
            return 0;
        }

        int left = max(helper(root->left, res), 0);
        int right = max(helper(root->right, res), 0);

        res = max(res, left+right+root->val);
        return root->val+max(left, right);
    }
};