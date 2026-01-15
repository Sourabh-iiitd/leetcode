class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n=stones.size();
        int prev=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(i%2!=0 && i!=n-1){
                continue;
            }
            maxi=max(maxi,abs(stones[i]-stones[prev]));
            prev=i;
        }
        for(int i=n-1;i>=0;i--){
            if(i%2==0 && i!=0){
                continue;
            }
            maxi=max(maxi,abs(stones[i]-stones[prev]));
            prev=i;
        }
        return maxi;
    }
};