class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        priority_queue<pair<int, pair<int,int>>,
                       vector<pair<int, pair<int,int>>>,
                       greater<>> pq;

        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : flights) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        pq.push({0, {src, 0}});
        dist[src][0] = 0;

        while (!pq.empty()) {
            int cost = pq.top().first;
            int node = pq.top().second.first;
            int cnt  = pq.top().second.second;
            pq.pop();

            if (node == dst) return cost;
            if (cnt == k + 1) continue;

            for (auto &[nxt, price] : adj[node]) {
                int newCost = cost + price;
                int newUsed = cnt + 1;
                if (newCost < dist[nxt][newUsed]) {
                    dist[nxt][newUsed] = newCost;
                    pq.push({newCost, {nxt, newUsed}});
                }
            }
        }
        return -1;
    }
};