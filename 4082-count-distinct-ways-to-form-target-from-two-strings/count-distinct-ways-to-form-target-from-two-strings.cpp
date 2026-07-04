class Solution {
public:
    int memo[101][101][101][2][2];
    const int MOD=1e9+7;

    int helper(int ti,int i,int j,bool used1,bool used2,string &word1,string &word2,string &target){
        if(ti==target.size()){
            return (used1&&used2);
        }

        if(memo[ti][i][j][used1][used2]!=-1){
            return memo[ti][i][j][used1][used2];
        }

        long long ans=0;
        char curr=target[ti];

        for(int k=i;k<word1.size();k++){
            if(word1[k]==curr){
                ans=(ans+helper(ti+1,k+1,j,true,used2,word1,word2,target))%MOD;
            }
        }

        for(int k=j;k<word2.size();k++){
            if(word2[k]==curr){
                ans=(ans+helper(ti+1,i,k+1,used1,true,word1,word2,target))%MOD;
            }
        }

        return memo[ti][i][j][used1][used2]=ans;
    }

    int interleaveCharacters(string word1,string word2,string target){
        memset(memo,-1,sizeof(memo));
        return helper(0,0,0,false,false,word1,word2,target);
    }
};