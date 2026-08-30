class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]].push_back(i);
        }
        int ans=0;
        for(auto it: mpp){
            bool ch=true;
            vector<int> idx=it.second;
            for(int j=0;j<idx.size()-1;j++){
                if(idx[j]+1!=idx[j+1]) {
                    ch=false;
                    break;
                }
            }
            if(ch) ans++;
        }
        return ans;
    }
};