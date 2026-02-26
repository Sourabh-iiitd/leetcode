class Solution {
public:
    void addone(string &s){
        int i=s.size()-1;

        while(i>=0 && s[i]=='1'){
            s[i]='0';
            i--;
        }

        if(i >= 0){
            s[i]='1';
        }
        else{
            s="1"+s;
        }
    }
    void div(string &s){
        s.pop_back();
    }
    int numSteps(string s) {
        int ans=0;

        while(s!="1"){
            if(s.back()=='0'){
                div(s);
            }
            else{
                addone(s);
            }
            ans++;
        }

        return ans;
    }
};