class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        for(int i=0;i<n;i++){
            while(nums[nums[i]-1] != nums[i]){
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        int miss=-1;
        int dup=-1;
        for(int i=0;i<n;i++){
            if(nums[i] != i+1) {
                miss= i+1;
                dup=nums[i];
            }
        }
        return dup;
    }
};