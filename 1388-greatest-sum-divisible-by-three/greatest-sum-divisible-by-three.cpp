class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(3,INT_MIN));

        dp[n][0]=0;
        dp[n][1]=INT_MIN;
        dp[n][2]=INT_MIN;

        for(int i=n-1;i>=0;i--){
            for(int rem=0;rem<3;rem++){
                int nrem=(nums[i]+rem)%3;
                int tk= nums[i]+ dp[i+1][nrem];
                int nk=dp[i+1][rem];
                dp[i][rem]=max(tk,nk);
            }
        }

        return dp[0][0];
    }
};