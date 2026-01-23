class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int c=0;
        while (true){
            bool check=true;
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]>nums[i+1]) {
                    check=false;
                    break;
                }
            }
            if(check==true) return c;
            int minsum=INT_MAX;
            int idx=-1;
            for(int i=0;i<nums.size()-1;i++){
                int currentSum = nums[i] + nums[i+1];
                if (currentSum < minsum) {
                    minsum = currentSum;
                    idx = i;
                }
            }

            nums[idx]=minsum;
            nums.erase(nums.begin() + idx + 1);
            c++;
   
        }
        return c;
        
        
    }
};