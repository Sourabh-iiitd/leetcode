class Solution {
public:
    int helper(int i, int prev, vector<vector<int>>& clips, int time, vector<vector<int>>& dp){
        int n = clips.size();

        if(clips[prev][1] >= time) return 0;
        if(i == n) return 1e9;

        if(dp[i][prev] != -1) return dp[i][prev];

        int take = 1e9;

        if(clips[i][0] <= clips[prev][1]) 
            take = 1 + helper(i + 1, i, clips, time, dp);

        int not_take = helper(i + 1, prev, clips, time, dp);

        return dp[i][prev] = min(take, not_take);
    }

    int videoStitching(vector<vector<int>>& clips, int time) {
        int n = clips.size();

        sort(clips.begin(), clips.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        int ans = 1e9;

        for(int i = 0; i < n; i++){
            if(clips[i][0] == 0){
                ans = min(ans, 1 + helper(i + 1, i, clips, time, dp));
            }
        }

        return ans == 1e9 ? -1 : ans;
    }
};