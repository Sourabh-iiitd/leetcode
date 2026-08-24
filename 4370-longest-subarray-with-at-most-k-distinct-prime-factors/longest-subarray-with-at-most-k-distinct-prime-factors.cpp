class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());

        vector<int> spf(mx+1); //smallst Pf

        for(int i=0;i<=mx;i++){
            spf[i]=i;
        }
        for(int i=2; i*i<=mx;i++){
            if(spf[i]==i) {
                for(int j=i*i;j<=mx;j+=i){
                    if(spf[j]==j) spf[j]=i;
                }
            }
        }

        vector<int> cnt(mx+1,0);
        int dist=0;
        int left=0;
        int ans=0;


        for(int r=0;r<n;r++){
            int x=nums[r];
            while(x>1){
                int p=spf[x];
                if(cnt[p]==0) dist++;
                cnt[p]++;
                while(x%p==0) x/=p;

            }

            while(dist>k){
                x=nums[left];
                while(x>1){
                    int p=spf[x];
        
                    cnt[p]--;
                    if(cnt[p]==0){
                        dist--;
                    }
                    while(x%p==0) x/=p;


                }
                left++;
            }
            ans=max(ans, r-left+1);
            
        }
        return ans;
        

    }
};