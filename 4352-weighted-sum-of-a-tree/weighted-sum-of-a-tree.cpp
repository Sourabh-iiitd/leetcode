class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> adj(n);

        for(int i=1;i<n;i++){ 
            int par=parent[i];
            adj[par].push_back(i);
        }
        vector<int> depth(n, 0);
        queue<int> q;

        q.push(0);
        depth[0]=1;
        int maxh=1;

        while(!q.empty()){
            int curr=q.front();
            q.pop();

            maxh=max(maxh, depth[curr]);

            for(auto node: adj[curr]){
                depth[node]=depth[curr]+1;
                q.push(node);
            }
        }
        long long ans=0;
        for (int i=0; i < n; ++i) {
            ans += 1LL * nums[i] * (maxh - depth[i] + 1);
        }

        return ans;

    }
};