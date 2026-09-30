class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int depth=0;
        int n=seq.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            if(seq[i]=='(') depth++;
            
            if(depth%2==0) ans[i]=1;
            else ans[i]=0;

            if(seq[i]==')') depth--;
            
        }
        return ans;
    }
};