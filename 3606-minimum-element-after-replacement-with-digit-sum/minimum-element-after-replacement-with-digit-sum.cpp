class Solution {
public: 
    int sm(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n=n/10;
        }

        return sum;
    }
    int minElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int x: nums){
            int s=sm(x);
            ans.push_back(s);
        }
        sort(ans.begin(),ans.end());
        return ans[0];
    }
};