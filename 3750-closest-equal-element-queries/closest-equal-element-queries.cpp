class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        int n = nums.size();
        int m = queries.size();

        unordered_map<int, vector<int>> mpp;
       
        vector<int> pos(n); 

        for (int i = 0; i < n; i++) {
            pos[i] = mpp[nums[i]].size(); 
            mpp[nums[i]].push_back(i);
        }

        for (int i = 0; i < m; i++) {
            int q_idx = queries[i];
            int num = nums[q_idx];
            vector<int>& ind = mpp[num];
            int sz = ind.size();

            if (sz == 1) {
                ans.push_back(-1);
                continue;
            }
            int k = pos[q_idx]; 
            
            
            int left = ind[(k - 1 + sz) % sz];
            int right = ind[(k + 1) % sz];

            int dis1 = abs(left - q_idx);
            int dis2 = abs(right - q_idx);

            ans.push_back(min(min(dis1, n - dis1), min(dis2, n - dis2)));
        }

        return ans;
    }
};