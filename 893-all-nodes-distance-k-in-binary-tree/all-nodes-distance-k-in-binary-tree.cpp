/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    void makeParent(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        makeParent(root);

        queue<TreeNode*> q;
        unordered_map<TreeNode*, int> mpp;   // visited

        q.push(target);
        mpp[target] = 1;

        int dist = 0;

        while(!q.empty()){
            if(dist == k) break;            
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !mpp.count(node->left)){
                    q.push(node->left);
                    mpp[node->left] = 1;
                }
                if(node->right && !mpp.count(node->right)){
                    q.push(node->right);
                    mpp[node->right] = 1;
                }
                if(parent.count(node) && !mpp.count(parent[node])){
                    q.push(parent[node]);
                    mpp[parent[node]] = 1;
                }
            }
            dist++;
        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};