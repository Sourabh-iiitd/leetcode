class Solution {
public:
    
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        int i = 0;
        vector<int> arr;
        while (i < n) {
            int count = 0;
            if (s[i] == '1') {
                while (i < n && s[i] == '1') {
                    count++;
                    i++;
                }
                arr.push_back(count);
            } else {
                while (i < n && s[i] == '0') {
                    count--;
                    i++;
                }
                arr.push_back(count);
            }
        }

      
        int totalOnes = 0;
        for (int x : arr) {
            if (x > 0) {
                totalOnes += x;
            }
        }

      
        int m = arr.size();
        int maxAns = totalOnes;

        for (int j = 1; j < m - 1; ++j) {
           
            if (arr[j] > 0 && arr[j - 1] < 0 && arr[j + 1] < 0) {
              
                int mergedZeroBlockAsOnes = abs(arr[j - 1]) + arr[j] + abs(arr[j + 1]);
                
        
                int currentTotal = mergedZeroBlockAsOnes + (totalOnes - arr[j]);
                
                maxAns = max(maxAns, currentTotal);
            }
        }

        return maxAns;


    }
};