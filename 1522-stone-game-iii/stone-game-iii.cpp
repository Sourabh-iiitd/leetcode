class Solution {
public:
    int n;
    int dp[50001][2];
    int solve(int i, int p, vector<int>& stoneValue ){
        if(i>=n) return 0;


        if(dp[i][p]!=-1) return dp[i][p];

        int res1=INT_MAX ;
        int res2=INT_MIN ;
        int stones=0;
        for(int x=1; x<=3 && i+x-1<n;x++){
            int curr=stoneValue[i+x-1];
            stones+=curr;

            if(p==1){
                res2=max(res2, stones+ solve(i+x, 0, stoneValue));
            }
            else{
                res1=min(res1, solve(i+x, 1, stoneValue));
            }
        }
        if (p==1) return dp[i][p]= res2;
        return dp[i][p]= res1;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        memset(dp,-1,sizeof(dp));
        n=stoneValue.size();  
        int tsum=0;
        for(int x:stoneValue){
            tsum+=x;
        }
        int alice=solve(0,1,stoneValue);
        int bob=tsum-alice;
        if(alice>bob) return "Alice";
        else if(bob>alice) return "Bob";
        else return "Tie";
    }
};