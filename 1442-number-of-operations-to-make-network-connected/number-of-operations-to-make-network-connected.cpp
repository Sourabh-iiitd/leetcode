class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, vector<int>& vis) {
        vis[i] = 1;
        for (auto& nei : adj[i]) {
            if(!vis[nei] ) dfs(nei, adj, vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size()<n-1) return -1;
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);
        for (auto& e : connections) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis);
                ans++;
            }
        }
        return ans-1;
    }
};