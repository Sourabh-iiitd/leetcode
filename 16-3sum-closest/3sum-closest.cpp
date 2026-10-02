class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n= nums.size();
        int ans=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int l= i+1;
            int r= n-1;

            while(l<r){
                
                int sm=nums[i]+ nums[l]+nums[r];
                if(sm==target) return sm;
                if(abs(target-sm)< abs(target-ans)) ans=sm;
                else if(sm<target) l++;
                else r--;
            }
        }
        return ans;
    }
};