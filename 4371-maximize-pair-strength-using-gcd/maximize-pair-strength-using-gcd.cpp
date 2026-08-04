class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n=nums.size();

        long long ans= LLONG_MIN;

        for(int i=0;i<n;i++){

            for(int j=i+1;j<n;j++){
                long long mult=(long long) nums[i]*nums[j];
                long long g= gcd(nums[i],nums[j]);
                ans=max(ans, mult/(g*g));
            }
        }
        return ans;
    }
};