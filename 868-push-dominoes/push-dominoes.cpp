class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        vector<int> left(n,0), right(n,0);

        int f=0;
        for(int i=0;i<n;i++){
            if(dominoes[i]=='R') f=n;
            else if(dominoes[i]=='L') f=0;
            
            else f=max(f-1,0);
            right[i]=f;
            
        }
        f=0;
        for(int i=n-1;i>=0;i--){
            if(dominoes[i]=='L') f=n;
            else if(dominoes[i]=='R') f=0;
            
            else f=max(f-1,0);
            left[i]=f;
            
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(left[i]==right[i]) ans+='.';
            else if(left[i]>right[i]) ans+='L';
            else ans+='R';
        }
        return ans;
    }
};