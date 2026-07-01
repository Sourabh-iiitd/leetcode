class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int i=n-1;
        long long ans=0;
        
        while(mul>0 && i>=0){
            ans+=(1LL* nums[i]*mul);
            mul--;
            i--;
            k--;
            if(k==0) break;
        }
        if(k>0) {
            while(k>0 && i>=0){
                ans+=nums[i];
                i--;
                k--;
            }
            
        }
        return ans;
    }
};