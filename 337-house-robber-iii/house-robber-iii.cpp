class Solution {
public:
    // Returns {max money if ROBBING root, max money if SKIPPING root}
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};

        // Post-order traversal (bottom-up)
        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // State 1: Rob this node -> children MUST be skipped
        int rob = root->val + left.second + right.second;

        // State 2: Skip this node -> take max option from each child independently
        int skip = max(left.first, left.second) + max(right.first, right.second);

        return {rob, skip};
    }

    int rob(TreeNode* root) {
        auto [rob_root, skip_root] = dfs(root);
        return max(rob_root, skip_root);
    }
};