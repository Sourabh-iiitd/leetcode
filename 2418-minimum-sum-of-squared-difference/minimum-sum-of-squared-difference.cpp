class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int k= k1+k2;
        long long ans=0;
        int n=nums1.size();
        vector<int> dff;
        for(int i=0;i<nums1.size();i++){
            dff.push_back(abs(nums1[i]-nums2[i]));
        }

        vector<int> modi(100001,0);
        for(int i=0;i<n;i++){
            modi[dff[i]]++;
        }

        for(int i=100000;i>0 && k>0;i--){
            if(modi[i]==0) continue;
            // int d=i;
            long long ops= min(k,modi[i]);
            modi[i]-= ops;
            modi[i-1]+=ops; 
            k-=ops;    
        }

        for(int i=1;i<=100000;i++){
            if(modi[i]>0) ans += 1LL * modi[i] * i * i;
        }
        return ans;

    }
};