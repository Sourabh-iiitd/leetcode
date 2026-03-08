class Solution {
public:

//extra space ni chahiye
    // int findDuplicate(vector<int>& nums) {
    //     int n = nums.size();

    //     unordered_map<int,int> mpp;
    //     for(int x:nums){
    //         mpp[x]++;
    //     }
    //     for(auto it:mpp){
    //         if(it.second>1) return it.first;
    //     }
    //     return -1;
    // }

//array modify b ni krni
    // int findDuplicate(vector<int>& nums) {
    //     int n = nums.size();

    //     for(int i=0;i<n;i++){
    //         while(nums[nums[i]-1] != nums[i]){
    //             swap(nums[i], nums[nums[i]-1]);
    //         }
    //     }
    //     int dup=-1;
    //     for(int i=0;i<n;i++){
    //         if(nums[i] != i+1) {
    //             dup=nums[i];
    //         }
    //     }
    //     return dup;
    // }

    //best BS
   int findDuplicate(vector<int>& nums) {
    int low = 1, high = nums.size()-1;

    while(low < high){
        int mid = (low + high)/2;

        int count = 0;
        for(int x : nums){
            if(x <= mid) count++;
        }

        if(count > mid)
            high = mid;
        else
            low = mid + 1;
    }

    return low;
} 


};