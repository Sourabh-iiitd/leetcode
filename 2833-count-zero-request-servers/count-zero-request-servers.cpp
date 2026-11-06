class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(),logs.end(), 
        [](auto &a, auto &b){
            return a[1]<b[1];
        });

        int m=queries.size();
        vector<pair<int,int>> q;
        for(int i=0;i<m;i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());

        int left=0;
        int right=0;
        int cnt=0;
        vector<int> ans(m);
        unordered_map<int,int> mp;
        for(auto &it : q){
            int idx= it.second;
            int curr= it.first;

            while(right<logs.size() && logs[right][1]<= curr){
                
                int idx= logs[right][0];
                if(mp[idx]==0)  cnt++;
                mp[idx]++;
                right++;
            }

            while(left<right && logs[left][1]<curr-x){
                int idx= logs[left][0];
                mp[idx]--;
                if(mp[idx]==0)cnt--;
                left++;
            }
            ans[idx]=n-cnt;
        }
        return ans;
    }
};