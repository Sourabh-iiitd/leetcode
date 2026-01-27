class Solution {
public:
    int convertTime(string current, string correct) {
       
        int curr = stoi(current.substr(0, 2)) * 60 + stoi(current.substr(3, 2));
        int corr = stoi(correct.substr(0, 2)) * 60 + stoi(correct.substr(3, 2));

 
        int diff = corr - curr;
        
        int op = 0;

        
        while (diff > 0) {
            if (diff >= 60) {
                diff -= 60;
            } else if (diff >= 15) {
                diff -= 15;
            } else if (diff >= 5) {
                diff -= 5;
            } else {
                diff -= 1;
            }
            op++;
        }

        return op;
    }
};