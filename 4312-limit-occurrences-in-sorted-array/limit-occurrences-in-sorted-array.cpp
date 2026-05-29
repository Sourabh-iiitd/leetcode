class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {

        unordered_map<int,int> mpp;
        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }

        for(int i=0;i<nums.size();i++){

            if(mpp[nums[i]] > 0){

                ans.push_back(nums[i]);

                mpp[nums[i]]--;

                if(mpp[nums[i]] >= k){
                    mpp[nums[i]] = k-1;
                }
            }
        }

        return ans;
    }
};