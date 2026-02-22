class Solution {
public:
    string maximumXor(string s, string t) {
        int ones = 0;
        int zero = 0;

        for(int i = 0; i < t.size(); i++){
            if(t[i] == '1') ones++;
            else zero++;
        }

        int n = s.size();
        string chk(n, ' ');

        for(int i = 0; i < n; i++){
            
            if(s[i] == '0'){
                if(ones > 0){
                    chk[i] = '1';
                    ones--;
                }
                else{
                    chk[i] = '0';
                    zero--;
                }
            }
            else{ 
                if(zero > 0){
                    chk[i] = '1';   
                    zero--;
                }
                else{
                    chk[i] = '0';   
                    ones--;
                }
            }
        }

        return chk;
    }
};