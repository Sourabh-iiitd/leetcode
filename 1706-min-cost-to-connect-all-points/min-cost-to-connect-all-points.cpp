class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int n=points.size();
        vector<int> vis(n,0);

        pq.push({0,0});
        int ans=0;

        while(!pq.empty()){
            auto it =pq.top();
            pq.pop();
            int idx=it.second;
            int wgt=it.first;

            if(vis[idx]==1) continue;
            vis[idx]=1;
            ans+=wgt;

            for(int in=0;in<n;in++){
                // if(idx!=in && vis[in]!){
                    int x1=points[idx][0];
                    int y1=points[idx][1];

                    int x2=points[in][0];
                    int y2=points[in][1];

                    int wgt1=abs(x2-x1)+abs(y2-y1);
                    pq.push({wgt1, in});
                }
            // }       
        }

        return ans;
    }
};