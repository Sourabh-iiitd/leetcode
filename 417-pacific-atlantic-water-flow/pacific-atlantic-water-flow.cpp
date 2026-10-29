class Solution {
public:
//apprach 1
    int xdir[4]={-1,0,1,0};
    int ydir[4]={0,-1,0, 1};
   
    int n,m;
    
    
    void dfs(int i, int j, int &true1, int &true2,vector<vector<int>>& heights, vector<vector<int>> &vis ){
        vis[i][j]=1;
        if(i==0 || j==0) true1=1;
        if(i==n-1 || j==m-1) true2=1;
        for(int idx=0;idx<4;idx++){
                int nx=i+xdir[idx];
                int ny=j+ydir[idx];
            if(nx<n && ny<m && nx>=0 && ny>=0  && !vis[nx][ny] ) {
                if(heights[nx][ny]<= heights[i][j]) dfs(nx, ny, true1, true2, heights, vis);
            }

        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        n=heights.size();
        m=heights[0].size();
        
        vector<vector<int>> ans;
        vector<vector<int>> vis(n, vector<int>(m,0));  
        
        for(int i=0;i<heights.size();i++){
            for(int j=0;j<heights[0].size();j++){
                for(auto &row : vis) fill(row.begin(), row.end(), 0);
                int cnt1=0;
                int cnt2=0;
                dfs(i,j, cnt1, cnt2, heights, vis);
                if(cnt1==1 && cnt2==1) ans.push_back({i,j}) ;
            }
        }
        return ans;
    }
};