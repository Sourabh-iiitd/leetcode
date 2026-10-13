class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int,vector<int>> mpp;
        for(int i=0;i<x.size();i++){
            mpp[x[i]].push_back(i);
        }
        vector<int> ymax;

        for(auto it:mpp){
            int maxi=INT_MIN;
            vector<int> chk= it.second;
            for(int i=0;i<chk.size();i++){
                maxi=max(maxi, y[chk[i]]);

            }
            ymax.push_back(maxi);
            
        }
        sort(ymax.begin(), ymax.end());
        int sz=ymax.size();
        if(sz<3) return -1;
        return ymax[sz-1]+ ymax[sz-2]+ ymax[sz-3];
    }
};
