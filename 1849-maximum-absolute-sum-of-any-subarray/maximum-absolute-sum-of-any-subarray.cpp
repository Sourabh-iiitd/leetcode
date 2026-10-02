class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum=0;
        int ans1=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans1=max(ans1, abs(sum));
            if(sum<0) {
                sum=0;
            }

        }
        sum=0;
        int ans2=INT_MAX;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans2=min(ans2, sum);
            if(sum>0) {
                sum=0;
            }

        }
        return max(ans1,abs(ans2));
    }
};