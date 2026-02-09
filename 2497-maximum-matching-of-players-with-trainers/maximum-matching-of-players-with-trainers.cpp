class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int ans=0;
        int n1=players.size();
        int n2=trainers.size();
        int i=0;
        int j=0;
        while(i<n1 && j<n2){
            if(trainers[j]>=players[i]) {
                
                i++;
                
            }
            j++;
        }
        return i;
        
    }
};