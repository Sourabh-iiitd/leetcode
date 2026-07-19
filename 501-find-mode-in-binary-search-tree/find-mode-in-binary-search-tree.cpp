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
    void helper(TreeNode* root,unordered_map<int,int>& mpp){
        if(root==NULL) return ;
        helper(root->left,mpp);
        helper(root->right,mpp);
        mpp[root->val]++;
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> mpp;
        helper(root,mpp);
        vector<int> ans;
        int maxi=INT_MIN;
        for(auto it: mpp){
            maxi=max(maxi, it.second);
        }
        for(auto it: mpp){
            if(it.second==maxi) ans.push_back(it.first);
        }
        return ans;

    }
};