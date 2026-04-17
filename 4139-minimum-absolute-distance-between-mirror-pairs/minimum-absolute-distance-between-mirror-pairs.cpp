class Solution {
public:
    int rev(int n){
        int ans=0;
        while(n>0){
            int x=n%10;
            ans=ans*10+x;
            n/=10;
        }
        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
     
        unordered_map<int,int> mpp;
        
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int k=rev(nums[i]);
            if (mpp.count(nums[i])){
                mini=min(mini, abs(mpp[nums[i]]-i));
            }
            mpp[k]=i;
        }
        
        if(mini==INT_MAX) return -1;
        return mini;
        
    }
};