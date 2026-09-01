class Solution{
public:
    int minMoves(vector<string>& classroom,int energy){
        int m=classroom.size();
        int n=classroom[0].size();
        int stx=-1;
        int sty=-1;
        int totalLitter=0;
        vector<vector<int>> id(m,vector<int>(n,-1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(classroom[i][j]=='S'){
                    stx=i;
                    sty=j;
                }
                else if(classroom[i][j]=='L'){
                    id[i][j]=totalLitter++;
                }
            }
        }

        if(totalLitter==0) return 0;

       
        queue<tuple<int,int,int,int>> q;

        
        vector<vector<vector<int>>> best(m,vector<vector<int>>(n,vector<int>(1<<totalLitter,-1)));

        q.push({stx,sty,energy,0});
        best[stx][sty][0]=energy;

        int steps=0;
        int dirs[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty()){
            int sz=q.size();

            while(sz--){
                auto [r,c,e,mask]=q.front();
                q.pop();

                if(mask==(1<<totalLitter)-1)return steps;

                for(auto&dir:dirs){
                    int nr=r+dir[0];
                    int nc=c+dir[1];

                    if(nr>=0&&nr<m&&nc>=0&&nc<n&&classroom[nr][nc]!='X'){
                        int nextE=e-1;
                        if(nextE<0)continue;

                        int nextMask=mask;
                        char cell=classroom[nr][nc];

                        if(cell=='L')
                            nextMask|=(1<<id[nr][nc]);
                        else if(cell=='R')
                            nextE=energy;

                        if(nextE>best[nr][nc][nextMask]){
                            best[nr][nc][nextMask]=nextE;
                            q.push({nr,nc,nextE,nextMask});
                        }
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};