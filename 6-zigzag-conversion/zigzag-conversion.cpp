class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1 || numRows >= s.size()) return s;

        string ans="";
        int n = s.size();

        vector<string> mk(numRows, "");

        int c = 0;          
        int row = 0;
        bool dir = true;    

        while(c < n){

            mk[row] += s[c];
            c++;

            if(dir){
                row++;
                if(row == numRows - 1) dir = false;
            }
            else{
                row--;
                if(row == 0) dir = true;
            }
        }

        for(auto &str : mk){
            ans += str;
        }

        return ans;
    }
};
