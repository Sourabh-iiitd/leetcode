class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==1) return 0;

        int i=0;
        int j=0;
        int maxLen=0;

        while (j<n) {

            if (nums[j]<=1LL*k*nums[i]) {
                maxLen=max(maxLen, j-i+1);
                j++;   
            } 
            else {
                i++;   
            }
        }
        return n-maxLen; 
    }
};
