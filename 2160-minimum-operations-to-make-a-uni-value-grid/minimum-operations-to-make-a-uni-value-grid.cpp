class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        int s = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                arr.push_back(grid[i][j]);
                s++;
            }
        }
        int rem = arr[0] % x;
        for (int val : arr) {
            if (val % x != rem) return -1;
        }

        sort(arr.begin(), arr.end());
        int ans = 0;

        int mid = arr[s / 2];
        for (int i = 0; i < s; i++) {
            ans += (abs(mid - arr[i])) / x;
        }

        return ans;
    }
};