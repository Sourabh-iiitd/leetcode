class Solution {
public:
    int n;
    int dp[101][50001];
    vector<int> nums;
    int solve(int i,int sum){
        if(sum==0) return 0;
        if(i>=n) return INT_MAX;

        if(dp[i][sum]!=-1) return dp[i][sum];

        int ans= solve(i+1,sum);

        int x=nums[i];
        int val=x;
        int ops=0;

        while(val>0){
            if(val<=sum){
                int rem= solve(i+1, sum-val);
                if(rem!=INT_MAX){
                    ans=min(ans, ops+rem);
                }
            }
            val/=2;
            ops++;
        }

        val=x*2;
        ops=1;

        while(val<=sum){
            
                int rem= solve(i+1, sum-val);
                if(rem!=INT_MAX){
                    ans=min(ans, ops+rem);
                }
            
            val*=2;
            ops++;
        }

        return dp[i][sum]=ans;

    }
    int minOperations(vector<int>& nums, int sum) {
        this->nums=nums;
        this->n=nums.size();
        memset(dp,-1,sizeof(dp));
        int res=solve(0, sum);
        return res==INT_MAX? -1 :res;
    }
};