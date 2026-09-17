class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        

        vector<int> pref(n, 1e9);
        vector<int> suff(n, 1e9);
        vector<int> len(n, 1e9);

        int l=0;
        int curr_sum=0;

        for(int r=0;r<n;r++){
            curr_sum+= arr[r];
            while(curr_sum > target){
                curr_sum-=arr[l];
                l++;
            }
            if(curr_sum ==target){
                len[l]= r-l+1;
            }
        }

        suff[n-1]=len[n-1];
        for(int i=n-2 ;i>=0;i--){
            suff[i]=min(suff[i+1], len[i]);
        }

        for(int i=0;i<n;i++){
            
            if (len[i] !=1e9 && i+len[i]-1<n){
                int end_idx=i+len[i]-1;
                pref[end_idx] = min(pref[end_idx], len[i]);
            }

        }

        

        for (int i=1;i<n;i++) {
            pref[i]=min(pref[i], pref[i-1]);
        }

        int ans=1e9;
        for (int i=0; i<n-1; i++) {
            if (pref[i] !=1e9 && suff[i+1] != 1e9){
                ans = min(ans, pref[i]+suff[i+1]);
            }
        }

        return ans>=1e9? -1:ans;

    }
};