class Solution {
public:
    int minSelection(vector<vector<int>>& availableIntervals, vector<vector<int>>& targetIntervals) {
        int n=targetIntervals.size();
        sort(targetIntervals.begin(), targetIntervals.end());
        
        vector<vector<int>> target;
        int l=targetIntervals[0][0];
        int r=targetIntervals[0][1];
        
        for(int i=1;i<n;i++){
            if(targetIntervals[i][0]<=r){
                r=max(r,targetIntervals[i][1]);
            }
            else{
                 target.push_back({l,r});
                l=targetIntervals[i][0];
                r=targetIntervals[i][1];
            }
           
        }
        target.push_back({l, r});

        sort(availableIntervals.begin(),availableIntervals.end());

        int m=availableIntervals.size();
        int ans=0;
        int j=0; 
        int curr= target[0][0];
        int cov=-1;
        for(int i=0;i<target.size();i++){
            int curr=target[i][0];
            int end=target[i][1];
            
            if(cov>=end) continue;
            
            if(cov>=curr){
                curr=cov;
            }
            
            while(cov<end){
                int maxR=cov;
                
                while(j<m && availableIntervals[j][0]<=curr){
                    maxR=max(maxR,availableIntervals[j][1]);
                    j++;
                }
                
                if(maxR<curr) return -1;
                
                if(maxR==cov) return -1;
                
                cov=maxR;
                ans++;
                curr=cov;
            }
            
        }
        return ans;
               
    }
};