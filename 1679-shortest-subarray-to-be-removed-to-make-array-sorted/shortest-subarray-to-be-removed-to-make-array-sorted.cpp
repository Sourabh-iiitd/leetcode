class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int st=0;
        int end=n-1;
        for(int i=0;i<n-1;i++){
            if(arr[i]<=arr[i+1]) {
                st=i+1;
            }else{
                break;
            }
        }
        if (st == n - 1) return 0;

        for(int i=n-1;i>0;i--){
            if(arr[i]>=arr[i-1]){
                end=i-1;
            }
            else break;

        }

        int ans=min(n-1-st, end);

        int i=0;
        int j=end;

        while(i<=st && j<n){
            if(arr[i]<=arr[j]){
                ans=min(ans, j-i-1);
                i++;
            }
            else j++;
        }
        return ans;

    }
};