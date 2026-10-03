class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int n=nums.size();
       int l=0;
       int len=INT_MAX;
       int curr_sm=0;

       for(int r=0;r<n;r++){
            curr_sm+=nums[r];
            while(curr_sm>= target){
                len=min(len, r-l+1);
                curr_sm-=nums[l];
                l++;
            }
       }

       return (len==INT_MAX)? 0 : len;

        

    }
};