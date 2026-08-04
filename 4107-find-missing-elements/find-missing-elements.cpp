class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> freq(101,0);
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        int mini= ranges:: min(nums);
        int maxi= ranges:: max(nums);
        for(int i=mini;i<=maxi;i++){
            if(freq[i]==0) ans.push_back(i);
        }
        return ans;

    }
};