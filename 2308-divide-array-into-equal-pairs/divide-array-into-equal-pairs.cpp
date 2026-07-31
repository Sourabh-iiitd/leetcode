class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n=nums.size();
        if(n%2!=0) return false;
        unordered_map<int,int> mpp;
        for(int x:nums) mpp[x]++;
        for(auto it:mpp) {
            if(it.second%2!=0) return false;
        }
        return true;
    }
};