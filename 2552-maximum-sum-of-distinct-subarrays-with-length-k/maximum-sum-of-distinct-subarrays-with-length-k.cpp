class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size(); 
        long long ans=0;
        long long sm=0;
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){

            mp[nums[i]]++;
            sm+=nums[i];

            if(i>=k) {
                sm-= nums[i-k];
                mp[nums[i-k]]--;

                if(mp[nums[i-k]]==0)
                    mp.erase(nums[i-k]);
            }

            if(i>=k-1 && mp.size()==k)
                ans=max(ans,sm);
        }

        return ans;
    }
};