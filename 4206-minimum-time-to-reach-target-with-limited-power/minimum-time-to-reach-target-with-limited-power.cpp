class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &edge:edges){
            int u=edge[0],v=edge[1],t=edge[2];
            adj[u].push_back({v,t});
        }

        priority_queue<tuple<long long,int,int>,vector<tuple<long long,int,int>>,greater<>> pq;
        vector<int> max_power_reached(n,-1);

        pq.push({0,-power,source});

        while(!pq.empty()){
            auto [t,neg_p,u]=pq.top();
            pq.pop();

            int p=-neg_p;

            if(u==target) return {t,p};

            if(p<=max_power_reached[u]) continue;
            max_power_reached[u]=p;

            if(p<cost[u]) continue;

            int next_p=p-cost[u];

            for(auto &edge:adj[u]){
                int v=edge.first;
                long long next_t=t+edge.second;
                pq.push({next_t,-next_p,v});
            }
        }

        return {-1,-1};
    }
};