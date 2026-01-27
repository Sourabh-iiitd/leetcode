class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int ans=0;
        int fuel=startFuel;
        int i=0;
        while(fuel<target){

            while(i<stations.size() && fuel>=stations[i][0]){
                pq.push(stations[i][1]);
                i++;
            }

            if(pq.empty()) return -1;
            int f=pq.top();
            fuel+=f;
            ans++;
            pq.pop();
        }
        return ans;
    }
};