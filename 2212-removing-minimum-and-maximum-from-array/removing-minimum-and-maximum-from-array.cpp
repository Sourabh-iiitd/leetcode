class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        
        int n=nums.size();
        if(n<2) return n;
        int maxidx=-1;
        int minidx=-1;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                maxidx=i;
            }
            if(nums[i]<mini){
                mini=nums[i];
                minidx=i;
            }
        }
        int i=min(minidx, maxidx);
        int j=max(minidx, maxidx);
        return min({j+1,n-i,(i+1)+(n-j)});


    }
};