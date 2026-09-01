class Solution {
public:
    vector<int> jobDifficulty;
    int n;
    int memo[301][11];
    int solve(int idx, int d){
        if(d==1){
            int maxi=jobDifficulty[idx];
            for(int i=idx;i<n;i++){
                maxi=max(jobDifficulty[i],maxi);
            }
            return maxi;
        }
        if( memo[idx][d] !=-1) return memo[idx][d];
        int maxD=0;
        int ans=INT_MAX;
        
        for(int i=idx;i<=n-d;i++){
            int nm=jobDifficulty[i];
            maxD=max(maxD, nm);

           int res =solve(i + 1, d - 1);
            if (res!=INT_MAX) {
                ans=min(ans, maxD+res);
            }
            


        }
        return memo[idx][d] =ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        memset( memo, -1, sizeof(memo));
        this->n=jobDifficulty.size();
        if(n<d) return -1;
        this->jobDifficulty=jobDifficulty;
        return solve(0,d);
    }
};