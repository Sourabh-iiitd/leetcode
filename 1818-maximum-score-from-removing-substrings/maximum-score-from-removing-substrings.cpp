class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string str = s;
        int ans = 0;

        if (x > y) {
         
            for (int i = 0; i < (int)str.size() - 1; i++) {
                if (str[i] == 'a' && str[i + 1] == 'b') {
                    str.erase(i, 2);
                    ans += x;
                    i -= 2;
                    if (i < -1) i = -1; 
                }
            }
            
            for (int i = 0; i < (int)str.size() - 1; i++) {
                if (str[i] == 'b' && str[i + 1] == 'a') {
                    str.erase(i, 2);
                    ans += y;
                    i -= 2;
                    if (i < -1) i = -1;
                }
            }
        } else {
          
            for (int i = 0; i < (int)str.size() - 1; i++) {
                if (str[i] == 'b' && str[i + 1] == 'a') {
                    str.erase(i, 2);
                    ans += y;
                    i -= 2;
                    if (i < -1) i = -1;
                }
            }
        
            for (int i = 0; i < (int)str.size() - 1; i++) {
                if (str[i] == 'a' && str[i + 1] == 'b') {
                    str.erase(i, 2);
                    ans += x;
                    i -= 2;
                    if (i < -1) i = -1;
                }
            }
        }

        return ans;
    }
};