class Solution {
public:
    map<pair<TreeNode*, bool>, int> memo;
    int solve(TreeNode* root, bool can) {
        if (!root) return 0;
        if (memo.count({root, can})) {
            return memo[{root, can}];
        }
        int res=0;
        if (can) {
        
            int rob=root->val + solve(root->left, false) + solve(root->right, false);

         
            int skip=solve(root->left, true) + solve(root->right, true);

            res=max(rob, skip);
        } else {

            res=solve(root->left, true) + solve(root->right, true);
        }
        return memo[{root, can}]=res;
    }

    int rob(TreeNode* root) {
        return solve(root, true);
    }
};