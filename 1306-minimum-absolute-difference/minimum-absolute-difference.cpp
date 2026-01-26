class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
         vector<vector<int>> ans;
        // int mini=arr[1]-arr[0];
        int mini=INT_MAX;
        for(int i = 0; i < arr.size() - 1; i++) {
            mini = min(mini, arr[i+1] - arr[i]);
        }
        for(int i=0;i<arr.size()-1;i++){
            if(abs(arr[i+1]-arr[i])==mini){
                if(arr[i+1]>arr[i]){
                     ans.push_back({arr[i],arr[i+1]});
                }
                else{
                    ans.push_back({arr[i+1],arr[i]});
                }
              
            }
        }
        return ans;
    }
};