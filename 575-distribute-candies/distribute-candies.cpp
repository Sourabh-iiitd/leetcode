class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> st;

        int n=candyType.size();
        int c=0;
        for(int i=0;i<n;i++){
            st.insert(candyType[i]);
        }
        int num=n/2;
        return min((int)st.size(), num); 
    }
};