class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
    
        unordered_map<int,int> mpp;
        for(int x: nums){
            mpp[x]++;
        }
        int ans=-1;
        for(int it:nums){
            int chk=mpp[it];
            bool got=true;
            for(auto it2:mpp){
                if(it!=it2.first && it2.second==chk) {
                    got=false;
                    break;
                }
            }
            if(got) {
                ans=it;
                break;
            }

        }
        return ans;
    }
};