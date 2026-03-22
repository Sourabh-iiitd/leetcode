class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adj(n);
        // int n=edges.size();
        int m=edges[0].size();
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        queue<int> q;
        q.push(0);
        unordered_set<int> st(restricted.begin(),restricted.end());
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            vis[0]=1;
            for(auto nodes:adj[curr]){
                if(!st.contains(nodes) && !vis[nodes]){
                    vis[nodes]=1;
                    q.push(nodes);
                }
            }
            
        }

        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]) ans++;
        }
        return ans;

    }
};