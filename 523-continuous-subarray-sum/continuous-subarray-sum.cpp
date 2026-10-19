class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int n= nums.size();
        vector<long long> pref(n+1,0);;
        int ans=false;
        mpp[0]=0;
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+nums[i];
            int rem=((pref[i+1]%k)+k)%k;
            if(mpp.find(rem) != mpp.end()){
                if(i + 1 - mpp[rem] >= 2)
                    return true;
            }
            else{
                mpp[rem] = i + 1;
            }
        }
        return ans;
        
    }
};