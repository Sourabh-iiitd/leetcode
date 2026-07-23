class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> pref(arr.begin(), arr.end());
        pref.insert(pref.begin(), 0);
        int sz=pref.size();

       
        for (int i=1;i<sz;i++) pref[i]^=pref[i - 1];

        int count=0;

       
        for (int start=0;start<sz;start++) {
            for (int end=start+1;end<sz;end++) {
                if (pref[start] == pref[end]){
                  
                    count+=end-start-1;
                }
            }
        }

        return count;
    }
};