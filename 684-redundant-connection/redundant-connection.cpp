class Solution {
public: 
    

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> adj(n+1);

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];

            vector<int> vis(n+1,0);
            queue<int> q;
            q.push(u);
            vis[u]=1;
            while(!q.empty()){
                int node=q.front();
                
                q.pop();
                if (node == v) {
                    return {u, v};
                }
                for (auto nbr : adj[node]) {
                    if (!vis[nbr]) {
                        vis[nbr] = 1;
                        q.push(nbr);
                    }
                }
                
                
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
            

        }
        return {};
    }
};