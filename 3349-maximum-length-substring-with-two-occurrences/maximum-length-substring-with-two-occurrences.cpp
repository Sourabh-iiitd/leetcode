class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> freq;
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.length(); ++right) {
            // Add current character to map
            freq[s[right]]++;

            // If frequency exceeds 2, shrink window from left
            while (freq[s[right]] > 2) {
                freq[s[left]]--;
                left++;
            }

            // Update maximum valid length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};