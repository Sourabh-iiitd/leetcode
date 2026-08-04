class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();
        vector<long long> pref(n);
        pref[0] = tasks[0];
        for (int i = 1; i < n; ++i) {
            pref[i] = pref[i - 1] + tasks[i];
        }

        long long total_tasks_time = pref.back();
        long long completed = 0;
        vector<int> ans;
        ans.reserve(shifts.size());

        for (int shift : shifts) {
            completed += shift;

            if (completed >= total_tasks_time) {
                ans.push_back(0);
                completed = 0; 
            } else {
                
                auto it = upper_bound(pref.begin(), pref.end(), completed);
                int completed_count = distance(pref.begin(), it);
                ans.push_back(n - completed_count);
            }
        }

        return ans;
    }
};