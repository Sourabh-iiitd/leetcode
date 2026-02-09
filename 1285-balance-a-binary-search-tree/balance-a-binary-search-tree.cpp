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
    int height(TreeNode *root){
        if(root==nullptr) return 0;
        int l=height(root->left);
        if(l==-1) return -1;
        int r=height(root->right);
        if(r==-1) return -1;
        if(abs(l-r)>1) return -1;
        return 1+max(l,r);
         
    }
    bool isBalanced(TreeNode* root) {
        if(height(root)==-1) return false;
        return true;
    }
    void inorder(TreeNode* node, vector<int> &ans){
        if(node==NULL){
            return;
        }
        inorder(node->left,ans);
        ans.push_back(node->val);
        inorder(node->right,ans);

    }
    TreeNode* build(vector<int> &ans, int l ,int r){
        if(l>r){
            return NULL;
        }
        int mid=(l+r)/2;
        TreeNode* root= new TreeNode(ans[mid]);
        root->left=build(ans,l,mid-1);
        root->right=build(ans,mid+1,r);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(isBalanced(root)) return root;
        vector<int> ans;
        inorder(root,ans);
        return build(ans,0,ans.size()-1);
    }
};