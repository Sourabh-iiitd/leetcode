class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(int x:bulbs){
            mpp[x]++;
        }
        for(auto it:mpp){
            if(it.second%2!=0) ans.push_back(it.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};