class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
       
        vector<vector<int>> adj(n);
        for (int i = 0; i < invocations.size(); i++) {
            int u = invocations[i][0];
            int v = invocations[i][1];
            adj[u].push_back(v);
        }

      
        vector<bool> vis(n, false);
        queue<int> q;

        q.push(k);
        vis[k] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (auto it : adj[current]) {
                if (!vis[it]) {
                    vis[it] = true;
                    q.push(it);
                }
            }
        }

       
        for (int i = 0; i < invocations.size(); i++) {
            int u = invocations[i][0]; 
            int v = invocations[i][1]; 

            if (!vis[u] && vis[v]) {
              
                vector<int> allMethods;
                for (int m = 0; m < n; ++m) {
                    allMethods.push_back(m);
                }
                return allMethods;
            }
        }

       
        vector<int> ans;
        for (int m = 0; m < n; m++) {
            if (!vis[m]) {
                ans.push_back(m);
            }
        }

        return ans;
    }
};