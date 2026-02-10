class Solution {
public:

    void inorder(TreeNode* node, vector<int> &ans){
        if(node == NULL) return;

        inorder(node->left, ans);
        ans.push_back(node->val);
        inorder(node->right, ans);
    }

    void fix(TreeNode* node, vector<int> &sorted, int &i){
        if(node == NULL) return;

        fix(node->left, sorted, i);

        node->val = sorted[i++];

        fix(node->right, sorted, i);
    }

    void recoverTree(TreeNode* root) {

        vector<int> ans;
        inorder(root, ans);

        vector<int> sorted = ans;
        sort(sorted.begin(), sorted.end());

        int i = 0;
        fix(root, sorted, i);
    }
};
