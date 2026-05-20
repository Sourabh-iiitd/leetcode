class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n1=A.size();
        int n2=B.size();
        vector<int> ans(n1,0);

        for(int i=0;i<n1;i++){
            unordered_set<int> st;
            for(int j=0;j<=i;j++){
                st.insert(B[j]);
            }
            for(int k=0;k<=i;k++){
                if(st.contains(A[k])) ans[i]=ans[i]+1;
            }

        }
       
        return ans;

    }
};