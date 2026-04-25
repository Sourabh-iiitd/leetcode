class Solution {
public:
    int solve(int i, vector<int>& net, vector<vector<int>>& req) {
        if (i == req.size()) {
            for (int x : net) {
                if (x != 0)
                    return -1e9;
            }
            return 0; 
        }
        int notTake = solve(i + 1, net, req);
        int u = req[i][0];
        int v = req[i][1];

        net[u]--;
        net[v]++;
        int take = 1 + solve(i + 1, net, req);
        net[u]++;
        net[v]--;
        return max(take, notTake);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> net(n, 0);
return solve(0, net, requests);
    }
};