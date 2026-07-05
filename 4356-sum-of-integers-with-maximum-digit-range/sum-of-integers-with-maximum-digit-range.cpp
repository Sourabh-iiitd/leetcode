class Solution {
public:
    int range(int n){
        int maxi=INT_MIN;
        int mini=INT_MAX;
        while(n>0){
            int x=n%10;
            maxi=max(maxi, x);
            mini=min(mini, x);
            n/=10;
        }
        return maxi-mini;
    }
    int maxDigitRange(vector<int>& nums) {
        int maxi=INT_MIN;
        for(int x:nums){
            int r=range(x);
            maxi=max(maxi,r);
        }
        int sm=0;
        for(int x:nums){
            int r=range(x);
            if(r==maxi) sm+=x;
        }
        return sm;
    }
};