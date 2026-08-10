class Solution {
public:
    int n;
    int memo[100001];
    bool helper(int i){
        if(i==n) return false;
        if (memo[i] != -1) return memo[i];
        for(int j=1; i+j*j<=n; j++){
            if(helper(i+j*j)==false) return memo[i] =true;
        }

        


        return memo[i] =false;
    }
    bool winnerSquareGame(int n) {
        this-> n=n;
        memset(memo, -1, sizeof(memo));
        return helper(0);
    }
};