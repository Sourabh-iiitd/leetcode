class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        vector<int> pref(n,0);
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }
        int ans=INT_MAX;
        for(int i=l;i<=r;i++){
            for(int j=n-1;j>=i-1;j--){
                int sum = (j == i - 1) ? pref[j] : pref[j] - pref[j - i];
                if (sum > 0) ans = min(ans, sum);
            }
        }
        return (ans==INT_MAX)? -1:ans;
        

    }
};