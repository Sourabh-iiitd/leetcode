class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        unordered_map<int,vector<int>> mpp;
        int maxi=0;
        for(auto num:arr){
            int bits=0;
            int n=num;
            while(n>0){
                int b=n&1;
                n=n>>1;
                if(b==1) bits++;
            }
            mpp[bits].push_back(num);
            maxi=max(maxi,bits);
        }
        vector<int> ans;
        for(int i=0;i<=maxi;i++){
            if(mpp[i].empty()) continue;
            sort(mpp[i].begin(),mpp[i].end());
            for(auto j:mpp[i]){
                ans.push_back(j);
            }
        }
        return ans;
    }
};