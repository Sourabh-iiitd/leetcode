class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {

        int n=difficulty.size();
        vector<pair<int,int>> jobs;
        for(int i=0; i < n; i++){
            jobs.push_back({difficulty[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());

        for(int i=1; i < n; i++){
            jobs[i].second=max(jobs[i].second, jobs[i-1].second);
        }

        int ans=0;

        for(int i=0; i < worker.size(); i++){

            int l=0, r=n-1, idx=-1;

           
            while(l <= r){
                int mid=(l+r)/2;

                if(jobs[mid].first <= worker[i]){
                    idx=mid;
                    l=mid + 1;
                }
                else r=mid - 1;
            }

            if(idx != -1){
                ans+=jobs[idx].second;
            }
        }

        return ans;
    }
};
