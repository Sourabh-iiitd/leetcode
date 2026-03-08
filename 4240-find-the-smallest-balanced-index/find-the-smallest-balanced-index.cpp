class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n=nums.size();
        vector<long long> left(n,0);
        vector<long double> right(n,0);

        long long sm=0;
        left[0]=0;

        for(int i=0;i<n-1;i++){
            sm+=nums[i];
            left[i+1]=sm;
        }

        right[n-1]=1;
        long double pr=1;

        for(int i=n-1;i>0;i--){
            pr*=nums[i];
            right[i-1]=pr;
        }

        for(int i=0;i<n;i++){
            if(left[i]==right[i]) return i;
        }

        return -1;
    }
};