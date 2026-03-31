class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>> dis(n, vector<int>(m,1e9));
        set<pair<int,pair<int,int>>> st;
        st.insert({0,{0,0}});
        dis[0][0]=0;
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
                    int newEffort=max(d,abs(heights[x][y]-heights[xn][yn]));
                    if(newEffort<dis[xn][yn]){
                        if(dis[xn][yn]!=1e9){
                            st.erase({dis[xn][yn],{xn,yn}});
                        }
                        dis[xn][yn]=newEffort;
                        st.insert({newEffort,{xn,yn}});
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
};