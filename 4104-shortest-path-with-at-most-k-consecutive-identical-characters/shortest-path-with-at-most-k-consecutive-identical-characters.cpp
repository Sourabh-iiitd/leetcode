class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
            int u=e[0];
            int v=e[1];
            int w=e[2];
            adj[u].push_back({v,w});
        }


        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));

    
        priority_queue<pair<int, pair<int,int>>,
                       vector<pair<int, pair<int,int>>>,
                       greater<>> pq;

        dist[0][1] = 0;
        pq.push({0, {0, 1}});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();
            int u = node.first;
            int cnt = node.second;

            if (d > dist[u][cnt]) continue;     
            if (u == n - 1) return d;            

            for (auto &[v, w] : adj[u]) {
                int nr = (labels[v] == labels[u]) ? cnt + 1 : 1;
                if (nr > k) continue;

                if (d + w < dist[v][nr]) {
                    dist[v][nr] = d + w;
                    pq.push({d + w, {v, nr}});
                }
            }
        }
        return -1;
    }
};