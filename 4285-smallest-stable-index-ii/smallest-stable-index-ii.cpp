class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int> left(n);
        vector<int> right(n);

        int leftmax=nums[0];
        left[0]=leftmax;
        for(int i=1;i<nums.size();i++){
            leftmax=max(leftmax, nums[i]);
            left[i]=leftmax;
        }
        int rightmax=nums[n-1];
        right[n-1]=rightmax;
        for(int i=n-2;i>=0;i--){
            rightmax=min(rightmax, nums[i]);
            right[i]=rightmax;
        }

        for(int i=0;i<n;i++){
            if(abs(left[i]-right[i])<=k) return i;
        }
        return -1;
    }
};