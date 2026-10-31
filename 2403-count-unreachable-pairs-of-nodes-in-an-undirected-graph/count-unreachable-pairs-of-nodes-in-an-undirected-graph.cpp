class Solution {
public:
    void dfs(int i, vector<vector<int>> &adj, vector<int> &vis, int &sz){
        vis[i]=1;
        sz++;                        
        for(auto &nei: adj[i]){
            if(!vis[nei]) dfs(nei, adj, vis, sz);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> c;
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]) {
                int sz=0;             
                dfs(i,adj,vis,sz);
                c.push_back(sz);
            }
        }

        vector<long long> pref(n);
        pref[0]=c[0];
        for(int i=1;i<c.size();i++){
            pref[i]=pref[i-1]+ c[i];
        }
        long long ans=0;
        for(int i =0;i<c.size();i++){
            int curr=c[i];
            if(i+1< c.size()){
                long long bef= pref[i];
                long long aft= pref[c.size()-1];
                long long tot= aft-bef;
                ans+= 1LL* curr * tot;
            }
        }
        return ans;
    }
};