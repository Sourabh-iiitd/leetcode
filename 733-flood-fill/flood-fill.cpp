class Solution {
public:
    void dfs( int sr, int sc, int color,vector<vector<int>>& image,
    vector<vector<int>>& vis){
        vis[sr][sc]=1;
        int init_color=image[sr][sc];
        image[sr][sc]=color;
        int xdir[4]={-1,0,1,0};
        int ydir[4]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nx=sr+xdir[i];
            int ny=sc+ydir[i];
            if(nx>=0 && ny>=0 && nx<image.size() && ny<image[0].size()&& image[nx][ny]==init_color && !vis[nx][ny]){

                dfs(nx,ny,color,image,vis);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        dfs(sr,sc,color,image,vis);
        return image;
    }
};