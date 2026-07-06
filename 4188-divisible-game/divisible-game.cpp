class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        long long MOD = 1e9 + 7;
        unordered_set<int> candidate_primes;
        candidate_primes.insert(2);

        for (int num : nums) {
            int temp = num;
            for (int i = 2; i * i <= temp; ++i) {
                if (temp % i == 0) {
                    candidate_primes.insert(i);
                    while (temp % i == 0) {
                        temp /= i;
                    }
                }
            }
            if (temp > 1) {
                candidate_primes.insert(temp);
            }
        }

        long long max_global_score = -1e18; 
        long long best_k = 2;

        for (int k : candidate_primes) {
            long long current_max = -1e18;
            long long running_sum = 0;

            for (int num : nums) {
                long long score = (num % k == 0) ? num : -num;
               
                if (running_sum < 0) {
                    running_sum = score;
                } else {
                    running_sum += score;
                }
                
                current_max = max(current_max, running_sum);
            }

            if (current_max > max_global_score) {
                max_global_score = current_max;
                best_k = k;
            } else if (current_max == max_global_score) {
                if (k < best_k) {
                    best_k = k;
                }
            }
        }

        
        long long result = (max_global_score % MOD) * (best_k % MOD);
        result = (result % MOD + MOD) % MOD;

        return result;
    }
};