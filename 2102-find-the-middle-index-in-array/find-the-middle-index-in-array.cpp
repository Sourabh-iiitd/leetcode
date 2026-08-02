class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> pref(n+1,0);
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+nums[i];
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            if ((pref[i]==pref[n]-pref[i+1])) {
                ans=i;
                break;
            }
        }
        return ans;

    }
};