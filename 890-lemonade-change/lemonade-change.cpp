class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int collect = 0;
        int l = 0;
        int five = 0;
        int ten = 0;
        int twenty = 0;
        while (l < bills.size()) {
            if (bills[l] == 5)
                five++;
            else if (bills[l] == 10) {

                if (five == 0)
                    return false;
                five--;
                ten++;

            } else {
                if (ten >= 1 && five >= 1) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
            l++;
        }
        return true;
    }
};