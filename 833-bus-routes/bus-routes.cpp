class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source==target) {
            return 0;
        }

        unordered_map<int, vector<int>> adj;
       
        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                int stop=routes[i][j];
                adj[stop].push_back(i);
            }
        }

        queue<int> que;
        vector<bool> visited(501, false);
        
        for (auto route : adj[source]){
            que.push(route);
            visited[route]=true;
        }

        int ans=1;
        while (!que.empty()) {
            int size=que.size();

            while(size--) {
                int route=que.front();
                que.pop();

                
                for (auto &stop: routes[route]) {
                    
                    if (stop == target) {
                        return ans;
                    }

                    
                    for (auto nextRoute : adj[stop]) {
                        if (!visited[nextRoute]) {
                            visited[nextRoute]=true;
                            que.push(nextRoute);
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};