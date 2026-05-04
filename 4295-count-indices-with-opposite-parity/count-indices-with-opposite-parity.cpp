class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        
        for(int i=0;i<n;i++){
            int odd=0;
            int ev=0;
            for(int j=i+1;j<n;j++){
                if(nums[j]%2==0) ev++;
                else odd++;
            }
            if(nums[i]%2==0) ans[i]=odd;
            else ans[i]=ev;

        }
        
        return ans;
    }
};