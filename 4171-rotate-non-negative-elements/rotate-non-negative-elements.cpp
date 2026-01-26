class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> op;
        for(int x:nums){
            if(x>=0) op.push_back(x);
        }
        int m=op.size();
        vector<int> lp(m, -1);
        
        if(m!=0)k = k % m;
        for(int i=0;i<m;i++){
            int newi=i-k;
            if(newi>=0) lp[newi]=op[i];
            else lp[m+newi]=op[i];
        }
        int l=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                nums[i]=lp[l];
                l++;
            }
        }
        return nums;
    }
};