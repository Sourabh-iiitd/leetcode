class Solution {
public:
    
    bool check(int mid,int n,vector<vector<pair<int,int>>>& adj,vector<bool>& online,long long k) {
        
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        
       
        vector<long long> dist(n,1e18); 
        
        dist[0]=0;
        pq.push({0,0}); 
        
        while (!pq.empty()) {
            long long co=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            if (co > dist[node]) continue;
            if (node == n-1) return co <= k;
            
            for (auto& it : adj[node]) {
                int adjNode=it.first;
                int costt=it.second;
                
              
                if (costt<mid) continue;
                
                
                if (adjNode!=n-1 && !online[adjNode]) continue;
                
                if (co+costt<dist[adjNode]) {
                    dist[adjNode]=co+costt;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        return dist[n-1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges,vector<bool>& online,long long k) {
        int n=online.size();
        vector<vector<pair<int,int>>> adj(n);
        
        for (int i=0; i<edges.size(); i++) {
            int u=edges[i][0];
            int v=edges[i][1];
            int c=edges[i][2];
            adj[u].push_back({v,c});
        }
        
       //bs
        int low=0;
        int high=1e9;
        int ans=-1;
        
        while (low <= high) {
            int mid=low+(high-low) / 2; 
            
           
            if (check(mid,n,adj,online,k)) {
                ans=mid;     
                low=mid+1;  
            } else {
                high=mid-1; 
            }
        }
        
        return ans;
    }
};