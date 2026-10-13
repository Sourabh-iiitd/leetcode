class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0) nums[i]= -nums[i];
        }
        sort(nums.begin(), nums.end());
        for(int i=n-1;i>=n/2;i--){
            int c=nums[i];
            ans+=c*c;
        }
        for(int i=0;i<n/2;i++){
            int c=nums[i];
            ans-=c*c;
        }

        return ans;
    }
};
//-3 -2 -1 1 2 3 
