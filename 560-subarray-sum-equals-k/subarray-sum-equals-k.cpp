class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int n= nums.size();
        vector<int> pref(n+1,0);;
        int ans=0;
        mpp[0]=1;
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+nums[i];
            int needed=pref[i+1]-k;
            if(mpp.find(needed)!= mpp.end()) ans+=mpp[needed];
            mpp[pref[i+1]]++;
        }
        return ans;


    }
};