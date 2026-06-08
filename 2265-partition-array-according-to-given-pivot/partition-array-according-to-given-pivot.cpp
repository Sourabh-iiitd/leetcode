class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
    
        vector<int> left, right, mid;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>pivot) right.push_back(nums[i]);
            else if(nums[i]<pivot) left.push_back(nums[i]);
            else mid.push_back(nums[i]);
        }
        vector<int> ans;
        for(int i=0;i<left.size();i++){
            ans.push_back(left[i]);
        }
        for(int i=0;i<mid.size();i++){
            ans.push_back(mid[i]);
        }
        for(int i=0;i<right.size();i++){
            ans.push_back(right[i]);
        }
        return ans;
    }
};