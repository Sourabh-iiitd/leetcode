class Solution {
public:
    int sm(int n){
        int s=0;
        while(n>0){
            s+=n%10;
            n=n/10;
        }
        return s;
    }

    int getLucky(string s, int k) {
        string num="";

        for(int i=0;i<s.size();i++){
            int dig=s[i]-96;
            string d=to_string(dig);
            num+=d;
        }

        int ans=0;

        while(k>0){

            ans=0;

            for(char ch : num){
                ans += ch-'0';
            }

            num = to_string(ans);

            k--;
        }

        return ans;
    }
};