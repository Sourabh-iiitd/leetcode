class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_set<int> st(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=1;i<=n;i++){
            if(st.find(i)==st.end()) return i;
        }
        return n+1;
    }
};