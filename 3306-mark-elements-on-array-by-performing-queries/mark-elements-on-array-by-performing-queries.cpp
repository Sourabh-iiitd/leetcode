class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> vis(n,0);

        vector<long long> ans(queries.size(), 0);
        vector<pair<int, int>> sorted_nums(n);
        long long sm=0;
        for(int j=0; j<n; j++) {
            sorted_nums[j] = {nums[j], j};
            sm += nums[j];
        }
        sort(sorted_nums.begin(), sorted_nums.end());
        int ptr = 0;
        for(int i=0;i<queries.size();i++){
            int ind=queries[i][0];
            int smallest=queries[i][1];

            if(vis[ind]==0) {
                vis[ind]=1;
                sm-=nums[ind];
            }



            while(smallest > 0 && ptr < n) {
                int val = sorted_nums[ptr].first;
                int original_idx = sorted_nums[ptr].second;
                
                if(vis[original_idx] == 0) {
                    vis[original_idx] = 1;
                    sm -= val;
                    smallest--;
                }
                ptr++;
            }
            ans[i]=sm;

        }

        return ans;
    }
};