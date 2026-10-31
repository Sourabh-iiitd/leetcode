class Solution {
public:
    bool isBip(int i, vector<vector<int>> &adj, vector<int> &color){
        color[i]=0;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int node= q.front();
            q.pop();
            for(auto &nei: adj[node]){
                if(color[nei]==-1) {
                    color[nei]= !color[node];
                    q.push(nei);
                }
                else if(color[nei]==color[node]) return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto &e: dislikes){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> color(n+1,-1);
        for (int i=1;i<=n;i++) {
            if (color[i]==-1) {
                if (!isBip(i, adj, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};