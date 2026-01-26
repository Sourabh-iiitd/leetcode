class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        // return nums[nums.size()-1]-nums[];
        int mini=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i+k-1<n){
                mini=min(mini,nums[i+k-1]-nums[i]);
            }
        }
        return mini;
        
    }
};