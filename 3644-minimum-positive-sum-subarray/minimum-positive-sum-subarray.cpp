class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        vector<int> pref(n+1,0);
        // pref[0]=nums[0];
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+nums[i];
        }
        int ans=INT_MAX;
        for(int i=l;i<=r;i++){
            for(int j=n;j>=i;j--){
                // int sum = (j == i - 1) ? pref[j] : pref[j] - pref[j - i];
                if (pref[j] - pref[j - i] > 0) ans = min(ans, pref[j] - pref[j - i]);
            }
        }
        return (ans==INT_MAX)? -1:ans;
        

    }
};