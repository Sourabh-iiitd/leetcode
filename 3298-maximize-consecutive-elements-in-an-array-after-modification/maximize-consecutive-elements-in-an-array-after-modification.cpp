class Solution {
public:
    vector<vector<int>> dp;
    int findm(int st, int target, vector<int> &nums){
        int j=lower_bound(nums.begin()+st, nums.end(), target)- nums.begin();
        if (j<nums.size() && nums[j] == target) return j;
        return -1;
        
    }
    int solve(int i, int inc, vector<int> &nums){
        if (dp[i][inc] != -1) return dp[i][inc];
        int curr=nums[i]+inc;
        //next curr+1
        int res=1;
        int j= findm(i+1,curr+1,nums);
        if(j!=-1) {
            res=max(res,1+ solve(j,0,nums));
        }
        j= findm(i+1,curr,nums);
        if(j!=-1) {
            res=max(res,1+ solve(j,1,nums));
        }
        return dp[i][inc] = res;

    }
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        dp.assign(n+1, vector<int>(2,-1));
        int ans=1;
        for(int i=0;i<n;i++){
            ans = max(ans,max(solve(i,0,nums), solve(i,1,nums)));
        }
        return ans;
    }
};