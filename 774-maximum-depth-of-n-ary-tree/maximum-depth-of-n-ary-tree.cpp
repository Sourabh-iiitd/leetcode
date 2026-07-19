/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;

        queue<pair<Node*,int>> q;
        q.push({root,1});
        int ans=INT_MIN;


        while(!q.empty()){
            int sz=q.size();
            
            for(int i=0;i<sz;i++){
                Node* curr=q.front().first;
                int depth=q.front().second;
                ans = max(ans, depth);
                q.pop();
                for(Node* child : curr->children){
                    if(child!=nullptr) q.push({child,depth+1});
                }
            }
            
        }
        return ans;
        

        
    }
};