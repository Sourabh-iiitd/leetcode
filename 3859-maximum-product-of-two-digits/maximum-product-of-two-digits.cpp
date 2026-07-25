class Solution {
public:
    int maxProduct(int n) {
        vector<int> w;
        while(n>0){
            int x=n%10;
            w.push_back(x);
            n/=10;
        }
        sort(w.begin(),w.end());
        int sz=w.size();
        return ((w[sz-1]*w[sz-2]));
    }
};