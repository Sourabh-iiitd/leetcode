class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
       int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                for(int j=i+1;j<nums.size();j++){
                    if (nums[j]==2){
                        ans=min(ans,abs(j-i));
                    }
                }
            }
            else if(nums[i]==2){
                for(int j=i+1;j<nums.size();j++){
                    if (nums[j]==1){
                        ans=min(ans,abs(j-i));
                    }
                }
            }
            else{
                continue;
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};