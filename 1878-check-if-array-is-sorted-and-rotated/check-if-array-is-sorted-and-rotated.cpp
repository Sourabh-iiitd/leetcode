class Solution {
public:
    bool check(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        while(i<n-1){
            if(nums[i+1]<nums[i]) {
                break;
            }
            i++;
        }
        if(i==n-1) return true;
        int j=i+1;
        while(j<n-1){
            if(nums[j+1]<nums[j]) return false;
            j++;
        }
        
        if(nums[n-1] > nums[0]) return false;
        
        return true;
    }
};