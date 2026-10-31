class Solution {
public:
    void dfs(int i, vector<vector<int>> &adj, vector<int> &vis, vector<int> &idx){
        vis[i]=1;
        idx.push_back(i);
        for(auto &nei: adj[i]){
            if(!vis[nei]) dfs(nei, adj, vis, idx);
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        for(auto &e:pairs){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]) {
                vector<int> idx;             
                dfs(i,adj,vis,idx);

                string chars="";
                for(auto &k: idx) chars+=s[k];  

                sort(idx.begin(), idx.end());    
                sort(chars.begin(), chars.end()); 

                for(int k=0;k<idx.size();k++){
                    s[idx[k]]=chars[k];          
                }
            }
        }
        return s;
    }
};