class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int ans=0;
        int k=0;
        for(int i=cost.size()-1; i>=0 ;i--){
            if(k==2){
                k=0;
                continue;
                
            }
            else{
                ans+=cost[i];
                k++;
            }
              
        }
        return ans;
    }
};