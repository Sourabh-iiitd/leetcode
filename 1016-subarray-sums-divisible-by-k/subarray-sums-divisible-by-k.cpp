class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int n=nums.size();
        mpp[0]=1;
        int ans=0;  //4 9 9 7 4 5
        vector<int> pref(n+1,0);
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+nums[i];
            int needed=(pref[i+1] % k + k) % k;
            if(mpp.find(needed)!= mpp.end()) ans+=mpp[needed];

            mpp[needed]++;

        }
        return ans;
   

    
        
    }
};