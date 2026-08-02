class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        
        unordered_map<int, int> cnt;
        for (int p : planks) {
            cnt[p]++;
        }

        unordered_map<int, int> total = cnt;

      
        vector<int> heights;
        for (auto entry : cnt) {
            heights.push_back(entry.first);
        }

      
        int U = heights.size();
        for (int i = 0; i < U; i++) {
            for (int j = i; j < U; j++) {
                int x = heights[i];
                int y = heights[j];
                int sum = x + y;
                int pairs = (i == j) ? cnt[x] / 2 : min(cnt[x], cnt[y]);

                total[sum] += pairs;
            }
        }
        int max_width = 0;
        for (auto entry : total) {
            max_width = max(max_width, entry.second);
        }

        return max_width;
    }
};