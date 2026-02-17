class Solution {
public:
   
    int countSetBits(int n) {
        int count = 0;
        while (n > 0) {
            count += (n % 2);
            n /= 2;
        }
        return count;
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

      
        for (int h = 0; h < 12; h++) {
            
            for (int m = 0; m < 60; m++) {
                
                
                if (countSetBits(h) + countSetBits(m) == turnedOn) {
                    
                    
                    string time = to_string(h) + ":";
                    if (m < 10) time += "0"; 
                    time += to_string(m);
                    
                    result.push_back(time);
                }
            }
        }
        return result;
    }
};