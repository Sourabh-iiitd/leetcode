class Solution {
public:
    int k;
    vector<int> arr;
    int n;
    int dp[501];
    int solve(int idx){
        if(idx==n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int limit=min(n, idx+k);
        int maxi=0;
        int ans=0;
        for(int i=idx;i<limit;i++){
            
            maxi=max(maxi, arr[i]);
            int len=i-idx+1;
            int sm= len*maxi + solve(i+1);

            ans=max(ans, sm);
            

        }
        return  dp[idx]= ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        this->k=k;
        this->n=arr.size();
        this->arr=arr;
        memset(dp, -1, sizeof(dp));
        return solve(0);
    }
};