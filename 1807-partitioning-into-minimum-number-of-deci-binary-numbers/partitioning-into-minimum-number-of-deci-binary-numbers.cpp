class Solution {
public:
    int minPartitions(string n) {
        char maxi = '0';
        for (char c : n) {
            maxi=max(maxi,c);
        }
        return maxi-'0';
    }
};