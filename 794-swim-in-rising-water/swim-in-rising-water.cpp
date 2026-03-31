class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> dis(n, vector<int>(m,1e9));
        set<pair<int,pair<int,int>>> st;
        st.insert({grid[0][0],{0,0}});
        dis[0][0]=grid[0][0];
        int xdir[4]={-1,0,1,0};
        int ydir[4]={0,1,0,-1};
        while(!st.empty()){
            auto it=*(st.begin());
            int x=it.second.first;
            int y=it.second.second;
            int d=it.first;
            st.erase(it);
            for(int i=0;i<4;i++){
                int xn=x+xdir[i];
                int yn=y+ydir[i];
                if(xn>=0 && yn>=0 && xn<n && yn<m ){
                    int ch=grid[xn][yn];
                    int absd=max(d,ch);
                    
                    if(absd<dis[xn][yn]){
                        if(dis[xn][yn]!=1e9){
                            st.erase({dis[xn][yn],{xn,yn}});
                        }
                        dis[xn][yn]=absd;
                        st.insert({dis[xn][yn],{xn,yn}});
                    }
                }
            }
        }
        



        return dis[n-1][m-1];
    }
};