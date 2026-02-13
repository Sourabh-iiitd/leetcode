class Solution {
public:
    void solve(vector<vector<char>>& board) {

        int n=board.size();
        int m=board[0].size();

        queue<pair<int,int>> q;

        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(board[i][j]=='O'){
                        q.push({i,j});
                        board[i][j]='#';
                    }
                }
            }
        }

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        while(!q.empty()){

            auto [row,col]=q.front();
            q.pop();

            for(int i=0;i<4;i++){

                int nrow=row+drow[i];
                int ncol=col+dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O'){
                    board[nrow][ncol]='#';
                    q.push({nrow,ncol});
                }
            }
        }

       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='#') board[i][j]='O';
            }
        }
    }
};
