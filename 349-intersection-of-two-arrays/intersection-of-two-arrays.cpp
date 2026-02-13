class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;
        for(int x:nums1){
            st.insert(x);
        }
        unordered_set<int> as;
        for(int x: nums2){
            if(st.contains(x)){
                as.insert(x);
            }
        }
        vector<int> ans;
        for(auto it:as){
            ans.push_back(it);
        }
        return ans;
    }
};