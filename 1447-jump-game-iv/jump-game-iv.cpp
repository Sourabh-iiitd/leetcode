class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        if (n<=1) return 0;


        unordered_map<int,vector<int>> mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]].push_back(i);
        }

        vector<int> vis(n,0);
        queue<int> q;

        q.push(0);
        vis[0]=1;
        int steps=0;

        while(!q.empty()){
            int sz=q.size();

            for (int k = 0; k < sz; k++) {
                int idx=q.front();
                q.pop();
                if(idx==n-1) return steps;
            
                if(idx-1>=0 && vis[idx-1]!=1) {
                    q.push(idx-1);
                    vis[idx-1]=1;
                }
                if(idx+1<n && vis[idx+1]!=1)  {
                    q.push(idx+1);
                    vis[idx+1]=1;
                }
                vector<int> ids=mpp[arr[idx]];
            
                for(auto it:ids){
                
                    if(vis[it]!=1){
                        q.push(it);
                        vis[it]=1;
                    } 
                }
                mpp.erase(arr[idx]);
            }
            steps++;
            
        }
        return 0;
    }
};