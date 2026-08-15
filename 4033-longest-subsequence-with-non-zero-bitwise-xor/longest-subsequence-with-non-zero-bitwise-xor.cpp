class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr=0;
        int ans=0;
        int n=nums.size();
        bool has=false;
        for(int x: nums){
            xr=xr^x;
            if(x!=0) has=true;
        }
        if(xr!=0) return n;
        
        return has? n-1:0;
        
    }
};