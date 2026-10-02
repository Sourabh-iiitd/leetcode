class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            int chk=target-nums[i];
            if(mpp.find(chk)!=mpp.end()){
                return {i, mpp[chk]};
            }

            mpp[nums[i]]=i;
        }
        return {};
    }
};