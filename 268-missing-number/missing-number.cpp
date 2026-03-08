class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<=n;i++){
            if(st.find(i)==st.end()) return i;
        }
        
        return -1;
    }
};