class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long sm=0;
        int n=nums.size();
        for(int x:nums){
            sm+=x;
        }

        long long leftsm=0;
        long long mini=LLONG_MAX;
        int ans=0;

        for(int i=0;i<nums.size();i++){
            leftsm+=nums[i];
            long long rightsm=sm-leftsm;

            long long leftavg=leftsm/(i+1);
            long long rightavg=0;
            if(i!=n-1){
                rightavg= rightsm/(n-i-1);
            }
            if(abs(rightavg-leftavg)<mini){
                mini=abs(rightavg-leftavg);
                ans=i;
            }
        }
        return ans;
    }
};