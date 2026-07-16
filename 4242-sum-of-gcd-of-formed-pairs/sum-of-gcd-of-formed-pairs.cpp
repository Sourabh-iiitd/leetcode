class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxi=INT_MIN;
        
        
        vector <int> prefixGcd(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi, nums[i]);
            prefixGcd[i]= gcd(maxi, nums[i]);
        }

        sort(prefixGcd.begin(), prefixGcd.end());
        long long sm=0;
        for(int i=0;i<nums.size()/2;i++){
            sm+=(gcd(prefixGcd[i],prefixGcd[nums.size()-i-1]));
        }
        return sm;


    }
};