class Solution {
public:
    void dfs(int i, vector<vector<int>> &ans,vector<int> &temp, vector<vector<int>>& graph, vector<int> &vis ){
        if(i==graph.size()-1){
            
            ans.push_back(temp);
        }
        vis[i]=1;
        
        for(auto &it : graph[i]){
           
            if(!vis[it]){
                 temp.push_back(it);
                dfs(it, ans, temp, graph, vis);
                temp.pop_back();
            }
           
        }
        
        vis[i]=0;
       

    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(0);
        dfs(0,ans,temp, graph, vis);
        return ans;
    }
};