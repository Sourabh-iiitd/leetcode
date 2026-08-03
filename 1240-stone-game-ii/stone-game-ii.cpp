class Solution {
public:
    int n;
    int dp[2][101][101];
    int solve_alice(int p, int i, int m, vector<int> &piles){
        if(i>=piles.size()) return 0;
        if(dp[p][i][m]!= -1) return dp[p][i][m];
        int stones=0;
        int res= (p==1)? -1: INT_MAX;
        for(int x=1;x<=min(2*m, n-i);x++)  {
            stones+=piles[i+x-1];
            if(p==1){ //alice turns do best
                res=max(res, stones+solve_alice(0,i+x, max(m,x), piles));
            }
            else{ //bob worst
                res=min(res, solve_alice(1,i+x, max(m,x), piles));
            }
        }  
        return  dp[p][i][m]=res;                   

    }
    int stoneGameII(vector<int>& piles) {
        this->n=piles.size();
        memset(dp,-1,sizeof(dp));
        return solve_alice(1,0,1,piles);
    }
};