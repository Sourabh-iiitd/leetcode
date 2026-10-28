class Solution {
public:
    void dfs(int source, vector<int> & vis, vector<vector<int>> & adj){
        vis[source]=1;
        for(auto &it: adj[source]){
           
            if(!vis[it]){
                dfs(it, vis, adj);
            }   
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto &it: edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        dfs(source, vis,adj);
        return vis[destination];
    }
};