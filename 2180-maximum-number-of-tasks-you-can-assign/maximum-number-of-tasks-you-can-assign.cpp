class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        
        int left = 0, right = min((int)tasks.size(), (int)workers.size());
        int result = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (canComplete(tasks, workers, pills, strength, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
    
private:
    bool canComplete(vector<int>& tasks, vector<int>& workers, int pills, int strength, int k) {
        if (k == 0) return true;
        
        // use k strongest workers for k easiest tasks
        deque<int> dq;
        int m = workers.size();
        
        // add k strongest workers to deque
        for (int i = m - k; i < m; i++) {
            dq.push_back(workers[i]);
        }
        
        int pillsLeft = pills;
        
        // process tasks from hardest to easiest (among first k tasks)
        for (int i = k - 1; i >= 0; i--) {
            int task = tasks[i];
            
            if (dq.back() + strength < task) {
                return false;
            }
            
            if (dq.back() >= task) {
                dq.pop_back();
            } else {
                // need to use a pill
                if (pillsLeft == 0) {
                    return false;
                }
                
                // find weakest worker who can do it with a pill
                bool found = false;
                for (int j = 0; j < dq.size(); j++) {
                    if (dq[j] + strength >= task) {
                        dq.erase(dq.begin() + j);
                        pillsLeft--;
                        found = true;
                        break;
                    }
                }
                
                if (!found) {
                    return false;
                }
            }
        }
        
        return true;
    }
};