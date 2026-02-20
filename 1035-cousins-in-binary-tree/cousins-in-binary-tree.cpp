class Solution {
public:
    TreeNode* p1 = nullptr;
    TreeNode* p2 = nullptr;
    int d1 = -1, d2 = -1;

    void dfs(TreeNode* root, TreeNode* parent, int depth, int x, int y) {
        if (!root) return;

        if (root->val == x) {
            p1 = parent;
            d1 = depth;
        }

        if (root->val == y) {
            p2 = parent;
            d2 = depth;
        }

        dfs(root->left, root, depth + 1, x, y);
        dfs(root->right, root, depth + 1, x, y);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, nullptr, 0, x, y);
        return (d1 == d2) && (p1 != p2);
    }
};