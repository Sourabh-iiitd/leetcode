class Solution {
public:
    void dfs(int i, vector<int> &vis,vector<vector<int>>& rooms){
        vis[i]=1;
        for(auto &it: rooms[i]){
           if(!vis[it]) dfs(it,vis,rooms);  
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> vis(n,0);

        dfs(0,vis,rooms);
        
        bool ans=true;
        for(auto &it: vis) ans=ans&it;
        return ans;
    }
};