class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int x:nums){
            mpp[x]++;
        }
        for(auto &it:mpp){
            if(it.second>=2){
                return it.first;
            }
        }
        return 0;

    }
};