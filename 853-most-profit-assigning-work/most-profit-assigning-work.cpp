class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int ans=0;
        for(int i=0;i<worker.size();i++){
            int maxi=INT_MIN;
            int idx=-1;
            for(int j=0;j<difficulty.size();j++){
                if(difficulty[j]<=worker[i]){
                    if(profit[j]>maxi){
                        maxi=profit[j];
                        idx=j;
                    }
                }
            }
            if(maxi!=INT_MIN){
                ans+=maxi;
            }
            
        }
        return ans;
        
    }
};