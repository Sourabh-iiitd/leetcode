class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        // sort(spells.begin(),spells.end());
        sort(potions.begin(),potions.end());
        for (int i=0; i<spells.size();i++){
            long long f=spells[i];
            int l=0;
            int r=potions.size()-1;
            int idx=potions.size();
            while(l<=r){
                int mid=(l+r)/2;
                if(f*potions[mid]>=success){
                    r=mid-1;
                    idx=mid;
                }
                else{
                    l=mid+1;
                }
            }
            ans.push_back(potions.size() - idx);
            
        }
        return ans;
    }
};