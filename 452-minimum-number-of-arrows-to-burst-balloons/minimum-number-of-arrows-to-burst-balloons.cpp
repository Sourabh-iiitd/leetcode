class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1]; 
        });
        int n=v.size();
        int c=1;
        int end=v[0][1];
        int i=1;
        while(i<n){
            if(v[i][0]<=end){
                i++;
            }
            else{
                c++;
                end=v[i][1];
                i++;
            }
        }
        return c;
    }
};