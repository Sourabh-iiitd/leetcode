class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<int> miss;
        unordered_set<int> chk(nums.begin(),nums.end());
        for(int i=lower;i<=upper;i++){
            if(!chk.count(i)) miss.push_back(i);
        }
        if (miss.empty()) return {};
        vector<vector<int>> ans;

        int st=miss[0];
        int prev=miss[0];
        for(int i=1;i<miss.size();i++){
            if(miss[i]==prev+1){
                prev=miss[i];
            }
            else{
                ans.push_back({st, prev});
                st = miss[i];
                prev = miss[i];
            }
            
                

            
            
           
        }
        ans.push_back({st,prev});
        return ans;
    }
};