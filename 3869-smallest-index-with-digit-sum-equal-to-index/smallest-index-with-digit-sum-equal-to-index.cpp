class Solution {
public:
    int sm(int n){
        int s=0;
        while(n>0){
            int x=n%10;
            s+=x;
            n/=10;
        }
        return s;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(i==sm(nums[i])) return i;
        }
        return -1;
    }
};