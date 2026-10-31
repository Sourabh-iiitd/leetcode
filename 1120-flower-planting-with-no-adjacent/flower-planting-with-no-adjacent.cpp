class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> graph(n + 1);
        for (auto& p : paths) {
            graph[p[0]].push_back(p[1]);
            graph[p[1]].push_back(p[0]);
        }

        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            bool used[5] = {false};
            for (int nb : graph[i]) {
                used[ans[nb]] = true;
            }
            for (int c = 1; c <= 4; c++) {
                if (!used[c]) {
                    ans[i] = c;
                    break;
                }
            }
        }
        return vector<int>(ans.begin() + 1, ans.end());
    }
};