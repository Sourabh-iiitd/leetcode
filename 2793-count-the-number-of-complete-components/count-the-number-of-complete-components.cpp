class Solution {
public: 

    void helper(int node, vector<vector<int>> &adj, vector<int> &vis, int &n, int &e){
        vis[node]=1;
        n++;
        for (auto it: adj[node]){
            e++;
            if(!vis[it]) helper(it, adj, vis, n,e);
        }
    }
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }   
        int ans=0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                int edges=0;
                int nodes=0;
                helper(i,adj,vis,nodes,edges);
                if(edges==(nodes*(nodes-1))) ans++;
            }
        }
        return ans;
        
    }
};