class Solution {
public:
    vector<int> pref;
    int memo[501][501];
    int n;
    int solve(int l, int r, vector<int>& stoneValue){
        if(l==r) return 0;
        if (memo[l][r]!=-1) return memo[l][r];
        int score=0;

        for(int i=l;i<r;i++){
            int lsum=pref[i]-pref[l]+stoneValue[l];
            int rsum=pref[r]-pref[i];

            if(lsum>rsum){
                score=max(score,rsum+solve(i+1,r,stoneValue));
            }
            else if(rsum>lsum){
                 score=max(score,lsum+solve(l,i,stoneValue));
            }
            else{
                score=max(rsum+solve(i+1,r,stoneValue) ,max(score,lsum+solve(l,i,stoneValue)));
            }
        }

        return memo[l][r] =score;
    }
    int stoneGameV(vector<int>& stoneValue) {
        this->n=stoneValue.size();
        pref.resize(n);
        memset(memo, -1, sizeof(memo));
        pref[0]=stoneValue[0];
        for (int i = 1; i < n; i++) {
            pref[i]=pref[i-1]+stoneValue[i];
        }

        return solve(0,n-1,stoneValue);
    }
};