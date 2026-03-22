class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        
        int limit = 6000;
        
        unordered_set<int> st(forbidden.begin(), forbidden.end());
        
        vector<vector<int>> vis(limit, vector<int>(2, 0));

        queue<pair<int, pair<int,int>>> q;
        //{pos, {steps, lastWasBack}}
        
        q.push({0, {0, 0}});
        vis[0][0] = 1;
        
        while(!q.empty()){
            auto it = q.front(); q.pop();
            
            int curr = it.first;
            int steps = it.second.first;
            int back = it.second.second;
            
            if(curr == x) return steps;
            
            // forward
            int temp = curr + a;
            if(temp < limit && !st.count(temp) && !vis[temp][0]){
                vis[temp][0] = 1;
                q.push({temp, {steps+1, 0}});
            }
            
            // backward (only if last wasn't backward)
            int temp2 = curr - b;
            if(back == 0 && temp2 >= 0 && !st.count(temp2) && !vis[temp2][1]){
                vis[temp2][1] = 1;
                q.push({temp2, {steps+1, 1}});
            }
        }
        
        return -1;
    }
};