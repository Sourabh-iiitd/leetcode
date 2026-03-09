class Solution {
public:

    // void allbs(int n,string s, vector<int> arr){
    //     if(s.size()==n){
    //         int num=stoi(s);
    //         arr.push_back(num);
    //         return ;
    //     }
    //     allbs(n,s+"1",arr);
    //     s.pop_back();
    //     allbs(bn,s+"0",arr);
    // }

    vector<vector<vector<vector<int>>>> dp;
    
    const int MOD = 1e9+7;

    int helper(int zero, int one,int last, int count, int limit){
        if(zero==0 && one==0){
            // ans.push_back(ba);
            return 1;
        }
        int ans=0;
        if(dp[zero][one][last][count] != -1) return dp[zero][one][last][count]%MOD;
        if(last==0){
            if(zero>0 && count<limit){
                // ba.push_back(0);
                ans=(ans+helper(zero-1,one,0,count+1,limit))%MOD;
                // ba.pop_back();
            }
            if(one>0){
                // ba.push_back(1);
                ans=(ans+helper(zero,one-1,1,1,limit))%MOD;
                // ba.pop_back();
            }
            
        }
        
        if(last==1){
            if(one>0 && count<limit){
                // ba.push_back(1);
                ans=(ans+helper(zero,one-1,1,count+1,limit))%MOD;
                // ba.pop_back();
            }
            if(zero>0){
                // ba.push_back(0);
                ans=(ans+helper(zero-1,one,0,1,limit))%MOD;
                // ba.pop_back();
            }
        }
        return dp[zero][one][last][count]= ans%MOD;

    }

    int numberOfStableArrays(int zero, int one, int limit) {
        // vector<int> ba;
        // vector<vector<int>> ans;
        // memset(dp,-1,sizeof(dp));
        dp = vector<vector<vector<vector<int>>>>(
        zero+1,
        vector<vector<vector<int>>>(
            one+1,
            vector<vector<int>>(
                2,
                vector<int>(limit+1, -1)
            )
        )
     );
        int ans=0;
        if(zero>0){
            // ba.push_back(0);
           ans=(ans+helper(zero-1,one,0,1,limit))%MOD;
            // ba.pop_back();
        }

        if(one>0){
            // ba.push_back(1);
            ans=(ans+helper(zero,one-1,1,1,limit))%MOD;
            // ba.pop_back();
        }

        // return ans.size();
        return ans%MOD;
    }
};