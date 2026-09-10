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
    int cnt=0;
    int solve(TreeNode *root, int &count){
        if(root==nullptr) {
            count=0;
            return 0;
        }
        int leftcnt=0;
        int rightcnt=0;
        int l=solve(root->left, leftcnt);
        int r=solve(root->right, rightcnt);

        int totalsm= l+r+root->val;
        count = leftcnt + rightcnt + 1;

        if(totalsm/count == root->val) cnt++;

        return totalsm;

        
    }
    int averageOfSubtree(TreeNode* root) {
        int totalNodes=0;
        solve(root, totalNodes);
        return cnt;
    }
};