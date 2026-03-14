class Solution {
public:
    int dfs(int st,vector<vector<int>> &adj,vector<int>& visited ){
        visited[st]=1; 
            
        for(auto it: adj[st]){
            if(!visited[it]){
                dfs(it,adj,visited);
            }
        }
        int ans=0;
        for(int i=0;i<visited.size();i++){
            if(visited[i]) ans++;
        }
        return ans;
        
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        
        for(int i = 0; i < n; i++){
            long long xi = bombs[i][0];
            long long yi = bombs[i][1];

            for(int j = 0; j < n; j++){
                if(i != j){
                    long long xj = bombs[j][0];   
                    long long yj = bombs[j][1];   
                    
                    long long dis = (xj-xi)*(xj-xi) + (yi-yj)*(yi-yj); 
                    
                    if(dis <= 1LL*bombs[i][2]*bombs[i][2]){ 
                        adj[i].push_back(j);
                    }
                }
            }
        }
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++){
            vector<int> vis(n);
            ans=max(ans,dfs(i,adj,vis));
        }
        return ans;
    }
};