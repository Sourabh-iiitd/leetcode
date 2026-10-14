class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum> 9*num) return "";

        string result="";

        while(sum>=9){
            result+= '9';
            sum-=9;
        }

        if(sum>0) result += to_string(sum);

        while (result.length() < num) {
            result += '0';
        }
        return result;
    }
};