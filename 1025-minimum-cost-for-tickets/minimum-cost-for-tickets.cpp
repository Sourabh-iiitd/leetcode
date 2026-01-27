class Solution {
    int dp[366];
public:

    int helper(vector<int>& days, int idx,vector<int>& costs){
        if(idx>=days.size()){
            return 0;
        }
        if (dp[idx] != -1) return dp[idx];
        int one=costs[0]+helper(days,idx+1,costs);
        int i=idx;
        while(i<days.size() && days[i]<days[idx]+7){
            i++;
        }
        int sev=costs[1]+helper(days,i,costs);
        int j=idx;
        while(j<days.size() && days[j]<days[idx]+30){
            j++;
        }
        int thirty=costs[2]+helper(days,j,costs);

        return dp[idx]=min(one,min(sev,thirty));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return helper(days,0,costs);
    }
};