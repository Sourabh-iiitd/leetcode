class Solution {
public:
    int n;
    int dp[101][5005];
    vector<int> nums;

    int solve(int i, int sum) {
        if (sum==0) return 0;
        if (i>=n) return 1e9; 
        if (dp[i][sum]!=-1) return dp[i][sum];

        
        int ans=solve(i+1, sum); //skip

       
        int divVal=nums[i];
        int divOps=0;

        while (divVal>0){
            long long mulVal=divVal;
            int mulOps=0;

            while (mulVal<=sum){
                int totalOps=divOps+mulOps;
                int rem=solve(i+1,sum-mulVal);
                if (rem<1e9){
                    ans=min(ans,totalOps+rem);
                }
                mulVal*=2;
                mulOps++;
            }

            divVal/=2;
            divOps++;
        }

        return dp[i][sum]=ans;
    }

    int minOperations(vector<int>& nums, int sum) {
        this->nums=nums;
        this->n=nums.size();
        memset(dp,-1,sizeof(dp));
        
        int res=solve(0,sum);
        return res>=1e9? -1:res;
    }
};