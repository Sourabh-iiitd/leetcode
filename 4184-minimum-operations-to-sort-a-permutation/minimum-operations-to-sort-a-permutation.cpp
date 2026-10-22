class Solution {
public:
    int solve(vector<int> &nums){
        
        int n=nums.size();
        if(n==1 && nums[0]==0) return 0;
        vector<int> v=nums;
        for(int i:nums){
            v.push_back(i);
        }

        //inc
        int c=1;
        for(int i=1;i<2*n;i++){
            if(v[i]<v[i-1]) c=1;
            else {
                c++;
                if(c==n) return i+1-n;
            }
        }
        //dec
        c=1;
        for(int i=1;i<2*n;i++){
            if(v[i]>v[i-1]) c=1;
            else {
                c++;
                if(c==n) return i+2-n;
            }
        }

        return 1e9;


    }
    int minOperations(vector<int>& nums) {
        int ans=solve(nums);
        reverse(nums.begin(), nums.end());
        ans = min(ans, solve(nums)+1);
        return (ans==1e9)? -1:ans;
    }
};