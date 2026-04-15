class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        vector<int> ind;
        int n=words.size();
        for(int i=0;i<n;i++){
            if(words[i]==target){
                ind.push_back(i);
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<ind.size();i++){
            int d=abs(ind[i]-startIndex);
            mini=min(mini,min(d,n-d));
        }
        if(mini==INT_MAX) return -1;
        return mini;

    }
};