class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            int chk=target-nums[i];
            if(mpp.find(chk)!=mpp.end()){
                int next=mpp[chk];
                if(next>i) return {i+1, next+1};
                else return  {next+1, i+1};
            }

            mpp[x]=i;
        }
        return {};
    }
};