class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int n=nums.size();
        int k=-1;
        int l=-1;
        long long ans=LLONG_MIN;                
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){               
                if(i==j) continue;               
                if(nums[i]+nums[j]==target && nums[i]>nums[j]) {
                    long long prod=(long long)nums[i]*nums[j];   
                    if(prod>ans){
                        ans=prod;
                        k=i;
                        l=j;
                    }
                }
            }
        }
        return {k,l};
    }
};