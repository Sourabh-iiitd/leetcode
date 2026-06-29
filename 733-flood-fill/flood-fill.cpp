class Solution {
public:
    int n,m;
    void dfs(int sr, int sc, int clr,vector<vector<int>>& image, vector<vector<int>> &vis, vector<vector<int>>& ans ){
        vis[sr][sc]=1;
        int val=image[sr][sc];
        ans[sr][sc]=clr;


        int xdir[4]={-1,0,1,0};
        int ydir[4]={0,1,0,-1};

        for(int k=0;k<4;k++){
            int nx=sr+xdir[k];
            int ny=sc+ydir[k];
            if(nx<n && ny<m && nx>=0 && ny>=0 && vis[nx][ny]!=1 && image[nx][ny]==val){
                dfs(nx,ny,clr,image,vis,ans);
                
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n=image.size();
        m=image[0].size();
        vector<vector<int>> ans=image;
        vector<vector<int>> vis(n, vector<int>(m,0));
        dfs(sr,sc,color,image,vis,ans);
        return ans;
        

    }
};