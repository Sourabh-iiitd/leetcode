class Solution {
public:
    int dp[501][501];
    int helper(vector<int>& nums1, vector<int>& nums2, int i, int j){
        if(i==nums1.size() || j==nums2.size()){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int match=INT_MIN;
        if(nums1[i]==nums2[j]){
            match=1+helper(nums1,nums2,i+1,j+1);
        }
        int mismatch=max(helper(nums1,nums2,i+1,j),helper(nums1,nums2,i,j+1));
        return dp[i][j]= max(match,mismatch);
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return helper(nums1,nums2,0,0);
    }
};