class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adj[u].push_back({v,w});
        }
        set <pair<int,int>> st;
        st.insert({0,k});
        
        vector<int> dis(n+1,1e9);
        // vis[k]=1;
        dis[k]=0;
        while(!st.empty()){
            auto it=*(st.begin());
            int node=it.second;
            int t=it.first;
            st.erase(it);
            if(t>dis[node]) continue;

            for(auto adjNode : adj[node]){
                int nd=adjNode.first;
                int d=adjNode.second;
                if(t+d<dis[nd]){
                    if(dis[nd]!=1e9){
                        st.erase({dis[nd],nd});
                    }
                    dis[nd]=d+t;
                
                    st.insert({d+t,nd});
                }
                
            
            }
        }
    
        int ans=0;
        for(int i=1;i<n+1;i++){
            ans=max(ans,dis[i]);
        }
        if(ans==1e9) return -1;
        return ans;

    }
};