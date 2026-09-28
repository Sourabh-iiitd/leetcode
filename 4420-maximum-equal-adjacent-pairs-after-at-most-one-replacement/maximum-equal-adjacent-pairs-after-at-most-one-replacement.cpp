class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n=nums.size();
        map<pair<int,int>,int> pairs;
        int ans2=0;
        int ans1=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]) ans1++;
            else{
                int u=min(nums[i],nums[i+1]);
                int v=max(nums[i],nums[i+1]);
                pairs[{u,v}]++;
                ans2= max(ans2, pairs[{u,v}]);
            }
        }
        return ans1+ans2;
    }
};