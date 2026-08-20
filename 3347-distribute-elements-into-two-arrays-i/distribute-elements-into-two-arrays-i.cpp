class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1,arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i=2;i<nums.size();i++){
            int no=nums[i];
            if(arr1.back()>arr2.back()) arr1.push_back(no);
            else if(arr2.back()>arr1.back()) arr2.push_back(no);
        }

        vector<int> ans;
        for(int x:arr1) ans.push_back(x);
        for(int x:arr2) ans.push_back(x);
        return ans;


    }
};