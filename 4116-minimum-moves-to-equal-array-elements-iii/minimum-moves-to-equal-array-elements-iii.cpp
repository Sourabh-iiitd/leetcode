class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int c=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
            }
        }

        for(int i=0;i<n;i++){
            c+=abs(nums[i]-maxi);
        }
        return c;
    }
};