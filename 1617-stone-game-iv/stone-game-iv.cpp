class Solution {
public:
    int n;
    int memo[100001];
    bool solve(int i) {
        if (i == n) return false;
        if (memo[i] != -1) return memo[i];

      
        for (int x = 1; i + x * x <= n; x++) {
        
            if (!solve(i + x * x)) {
                return memo[i] = true;
            }
        }

        return memo[i] = false; 
    }

    bool winnerSquareGame(int n) {
        this->n = n;
        memset(memo, -1, sizeof(memo));
        return solve(0);
    }
};