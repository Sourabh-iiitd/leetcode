class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n= nums.size();
        int ans=0;

        unordered_map<long,int> mpp[n];

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                long diff= (long)nums[i]-nums[j];

                auto it= mpp[j].find(diff);

                int cntj=( it==end(mpp[j]))? 0 : it->second;
                mpp[i][diff]+= cntj+1;
                ans+=cntj;
            }
        }
        return ans;
    }
};