class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            int maxi=INT_MIN;
            int mini=INT_MAX;
            for(int k=0;k<=i;k++ ){
                maxi=max(maxi,nums[k]);
            }
            for(int k=i;k<nums.size();k++ ){
                mini=min(mini,nums[k]);
            }
            if(maxi-mini<=k) return i;
        }
        return -1;
    }
};