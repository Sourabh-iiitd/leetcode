class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || numRows>=s.size()) return s;
        string ans="";
        int n=s.size();
        vector<string> st(numRows,"");
        bool dir=true;
        int i=0;
        int row=0;
        int c=0;
        while(c<n){
            st[row]+=s[i];
            i++;
            c++;
            if(dir){
                row++; 
                if(row==numRows-1) dir=false;
            }
            else{
                row--;
                if(row==0) dir=true;
            }

        }
        for(string s:st){
            ans+=s;
        }
        return ans;
    }
};