class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int ans=0;

        int n=nums.size();

        for(int i=0;i<n;i++){
            int x=0;
            int y=0;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0) x++;
                if(nums[j]%2!=0) y++;
                
                if(y>0 && ((long long)x*b <= (long long)a*y)) ans++;
            }
            
        }

        return ans;
    }
};