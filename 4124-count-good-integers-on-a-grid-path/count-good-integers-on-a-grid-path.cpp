class Solution {
public:
    vector<int> path;
    long long dp[17][2][11][8];
    string num;
    
    long long dfs(int pos, int tight, int last, int pidx){
        if(pos==16) return pidx==7;
        if(dp[pos][tight][last][pidx]!=-1) return dp[pos][tight][last][pidx];
        long long res=0;
        int limit=tight?(num[pos]-'0'):9;
        for(int d=0;d<=limit;d++){
            int ntight=(tight&&(d==limit));
            int npidx=pidx;
            int nlast=last;
            if(pidx<7 && pos==path[pidx]){
                if(last!=10 && d<last)continue;
                nlast=d;
                npidx++;
            }
            res+=dfs(pos+1,ntight,nlast,npidx);
        }
        return dp[pos][tight][last][pidx]=res;
    }

    long long solve(long long x, string directions){
        if(x<0)return 0;
        string s=to_string(x);
        if(s.length()<16) s=string(16-s.length(),'0')+s;
        num=s;
        path.clear();
        int r=0,c=0;
        path.push_back(0);
        for(char d:directions){
            if(d=='D')r++;
            else c++;
            path.push_back(r*4+c);
        }
        memset(dp,-1,sizeof(dp));
        return dfs(0,1,10,0);
    }

    long long countGoodIntegersOnPath(long long l, long long r, string directions){
        return solve(r,directions)-solve(l-1,directions);
    }
};