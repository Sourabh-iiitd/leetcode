class Solution {
public:
    int n;
    int getNext(vector<vector<int>> &arr, int st, int currEnd){
        int l=st;
        int r=n-1;
        int next=n;
        while(l<=r){
            int m= l+(r-l)/2;
            if(arr[m][0]>= currEnd){
                next=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return next;
    }

    vector<int> dp;
    
    int solve(vector<vector<int>> &arr, int idx){
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int ntake=solve(arr, idx+1);

        int next=getNext(arr, idx+1, arr[idx][1]);
        int take= arr[idx][2]+ solve(arr,next);

        return dp[idx]=max(ntake,take);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        this-> n=profit.size();
        vector<vector<int>> arr(n,vector<int>(3,0));

        for(int i=0;i<n;i++){
            arr[i][0]=startTime[i];
            arr[i][1]=endTime[i];
            arr[i][2]=profit[i];
        }

        sort(arr.begin(), arr.end());
        
        dp.assign(n, -1); 
        return solve(arr,0);
    }
};