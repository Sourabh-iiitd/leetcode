class Solution {
public:
    int memo[501][501];
    int helper(int st, int end, vector<int>& piles){
        if(st==end) return piles[st];
        int pickst = piles[st] - helper( st + 1, end,piles);
        
       if (memo[st][end] != -1) {
            return memo[st][end];
        }
        int pickEnd = piles[end] - helper( st, end - 1,piles);

       
        return memo[st][end] = max(pickst, pickEnd);

    }
    bool stoneGame(vector<int>& piles) {
        memset(memo,-1,sizeof(memo));
        return helper(0,piles.size()-1, piles)>=0;
    }
};