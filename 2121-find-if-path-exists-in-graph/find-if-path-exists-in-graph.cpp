class Solution {
public:
    bool dfs(int source,int destination, vector<int> & vis, vector<vector<int>> & adj){
        if (source == destination)
        return true;

        vis[source]=1;
        for(auto &it: adj[source]){
           
            if(!vis[it]){
                if(dfs(it, destination,vis, adj)){
                    return true;
                };
            }   
        }
        return false;
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
        return dfs(source, destination, vis, adj);
    }
};