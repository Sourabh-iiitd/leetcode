class Solution {
public:
    int xorOperation(int n, int start) {
        
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=start+(2*i);
        }
        int a=ans[0];
        for(int i=1;i<n;i++){
            a=a^ans[i];
        }
        return a;
    }
};