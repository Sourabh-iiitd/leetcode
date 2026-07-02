class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int mini=-1;
        for(int num: nums){
            mini=mini&num;
        }
        if(mini!=0) return 1;
        
        int ans=0;
        
        int current_and=-1;
        
        for(int i=0; i < nums.size(); i++){
            current_and &= nums[i];
            
           
            if(current_and==0) {
                ans++;
                current_and=-1; 
            }
        }


        return ans;
    }
};