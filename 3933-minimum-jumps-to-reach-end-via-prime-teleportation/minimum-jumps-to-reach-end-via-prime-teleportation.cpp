class Solution {
public:
    
    unordered_map<int, bool> is_prime_cache;

    bool prime(int n) {
        if (n <= 1) return false;
        if (is_prime_cache.count(n)) return is_prime_cache[n];
        
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return is_prime_cache[n] = false;
            }
        }
        return is_prime_cache[n] = true;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> prime_to_indices;
        for (int i = 0; i < n; i++) {
            int temp = nums[i];
         
            for (int j = 2; j * j <= temp; j++) {
                if (temp % j == 0) {
                    prime_to_indices[j].push_back(i);
                    while (temp % j == 0) {
                        temp /= j;
                    }
                }
            }
          
            if (temp > 1) {
                prime_to_indices[temp].push_back(i);
            }
        }

        vector<int> index_visited(n, 0);
        unordered_set<int> prime_visited;
        index_visited[0] = 1;
        
        queue<pair<pair<int, int>, int>> q;
        q.push({{nums[0], 0}, 0});

        while (!q.empty()) {
            int curr = q.front().first.first;
            int idx = q.front().first.second;
            int step = q.front().second;
            q.pop();

            if (idx == n - 1)
                return step;

            if (idx - 1 >= 0 && !index_visited[idx - 1]) {
                index_visited[idx - 1] = 1;
                q.push({{nums[idx - 1], idx - 1}, step + 1});
            }
            if (idx + 1 < n && !index_visited[idx + 1]) {
                index_visited[idx + 1] = 1;
                q.push({{nums[idx + 1], idx + 1}, step + 1});
            }

            if (prime(nums[idx]) && prime_visited.find(nums[idx]) == prime_visited.end()) {
                prime_visited.insert(nums[idx]);
                
                
                if (prime_to_indices.count(nums[idx])) {
                    for (int i : prime_to_indices[nums[idx]]) {
                        if (!index_visited[i]) {
                            index_visited[i] = 1;
                            q.push({{nums[i], i}, step + 1});
                        }
                    }
                }
            }
        }

        return -1;
    }
};