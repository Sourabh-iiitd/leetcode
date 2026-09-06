class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n=position.size();

        vector<int> grpspeed;
        for(int i=0;i<n;i++){
            if(i==n-1 || position[i+1]-position[i]>distance){
                grpspeed.push_back(speed[i]);
            }
        }

        int ans=0;
        int minSpeedToRight = 2e9 + 7;
        for(int i=grpspeed.size()-1;i>=0;i--){
            if (grpspeed[i] <= minSpeedToRight) {
                ans++;
                minSpeedToRight = grpspeed[i];
            }
        }


        return ans;
    }
};