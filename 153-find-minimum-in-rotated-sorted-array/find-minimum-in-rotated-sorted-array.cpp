class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
    
        int low=0;
        int high=n-1;
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[low]<nums[high]){ //  if left half(arr[low]<arr[mid]) and right half(arr[mid]<=arr[high]) BOTH SORTED MEANS FULL ARRAY SORTED DIRECTLY RETURN arr[LOW] AND wrtie condition combinedly as arr[low]<=arr[high]
                ans=min(ans,nums[low]);
                break;
            }
            if(nums[low]<=nums[mid]){
                ans=min(ans,nums[low]);
                low=mid+1;
            }
            else{
                ans=min(ans,nums[mid]);
                high=mid-1;
            }
        }
        return ans;

    }
};