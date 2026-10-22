class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        vector<int> h(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            if(i+k>= nums.size()){
                h[i+k-nums.size()]= nums[i];
            }
            else{
                h[i+k]=nums[i];
            }
        }
         for(int i=0;i<nums.size();i++){
            nums[i]=h[i];
         }
    }
};