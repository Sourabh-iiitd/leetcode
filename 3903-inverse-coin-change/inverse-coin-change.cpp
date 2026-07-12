class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        vector<int> coins;
        vector<long long> dp(n+1,0);
        dp[0]=1;
        for(int coin=1;coin<=n;++coin)
        {
            if(dp[coin]>numWays[coin-1]) return {};
            if(dp[coin]<numWays[coin-1])
            {
                coins.push_back(coin);
                for(int s=coin;s<=n;++s)
                {
                    dp[s] += dp[s-coin];
                }
            }
        }
        for(int i=1;i<=n;++i)
        {
            if(dp[i]!=numWays[i-1]) return {};
        }
        return coins;
    }
};