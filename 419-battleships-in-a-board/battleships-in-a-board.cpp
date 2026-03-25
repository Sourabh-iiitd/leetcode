class Solution {
public:
    void dfs(int i,int j, vector<vector<char>>& board, vector<vector<int>> &vis ){
        vis[i][j]=1;
        if(i+1<board.size() && board[i+1][j]=='X' && !vis[i+1][j]){
            dfs(i+1, j,board, vis);
        }
        else if(j+1<board[0].size() && board[i][j+1]=='X'  && !vis[i][j+1]){
            dfs(i,j+1,board,vis);
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='X') {
                    dfs(i,j,board,vis);
                    c++;
                }
            }
        }
        return c;
    }
};