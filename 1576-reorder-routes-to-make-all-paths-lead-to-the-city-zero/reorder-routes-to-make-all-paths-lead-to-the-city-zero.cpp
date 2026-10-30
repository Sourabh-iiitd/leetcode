class Solution {
public:
    int total=0;
    void dfs(int node, int parent, vector<vector<pair<int,int>>> &adj){
        for(auto &nei: adj[node]){
            int nxt= nei.first;
            int isOrginialdir= nei.second;

            if(nxt != parent){
                if (isOrginialdir == 1) {
                    total++;
                }
                dfs(nxt, node, adj);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        vector<int> vis(n,0);
        for(auto e: connections){
            int u=e[0];
            int v=e[1];
            adj[u].push_back({v,1});
            adj[v].push_back({u,0});
        }
        
        dfs(0,-1,adj);
        return total;
    }
};
