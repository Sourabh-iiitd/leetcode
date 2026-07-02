class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges,
                                      int power, vector<int>& cost,
                                      int source, int target) {

        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<map<int,long long>> dist(n);

        using T = tuple<long long,int,int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        dist[source][power] = 0;
        pq.push({0, source, power});

        while (!pq.empty()) {

            auto [t, node, rem_power] = pq.top();
            pq.pop();

            auto itCur = dist[node].find(rem_power);
            if (itCur == dist[node].end() || itCur->second != t)
                continue;

            if (node == target)
                continue;

            if (rem_power < cost[node])
                continue;

            int next_power = rem_power - cost[node];

            for (auto &[next_node, wt] : adj[node]) {

                long long new_time = t + wt;

                // --------- Dominance check ----------
                bool dominated = false;

                auto it = dist[next_node].lower_bound(next_power);

                while (it != dist[next_node].end()) {
                    if (it->second <= new_time) {
                        dominated = true;
                        break;
                    }
                    ++it;
                }

                if (dominated)
                    continue;

                // Remove dominated states
                it = dist[next_node].begin();

                while (it != dist[next_node].end()) {
                    if (it->first <= next_power && it->second >= new_time)
                        it = dist[next_node].erase(it);
                    else
                        ++it;
                }

                dist[next_node][next_power] = new_time;
                pq.push({new_time, next_node, next_power});
            }
        }

        long long min_time = LLONG_MAX;
        int max_power = -1;

        for (auto &[p, tm] : dist[target]) {
            if (tm < min_time) {
                min_time = tm;
                max_power = p;
            } else if (tm == min_time) {
                max_power = max(max_power, p);
            }
        }

        if (min_time == LLONG_MAX)
            return {-1, -1};

        return {min_time, max_power};
    }
};