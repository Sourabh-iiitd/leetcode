class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> freq(51,0);

        for(int i=0;i<=n-k;i++){
            vector<bool> seen(51, false);
            for(int j=i;j<i+k;j++){
                seen[nums[j]]=true;
            }
            for (int val=0;val<=50;val++) {
                if (seen[val]) freq[val]++;
            }
        }
       
        int ans=-1;
        
        for(int i=0;i<51;i++){
            if(freq[i]==1) {
                ans=max(ans,i);
            }
        }

        return ans;
    }
};