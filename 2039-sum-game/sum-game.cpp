class Solution {
public:
    bool sumGame(string s) {
       
        int n=s.size();

        int leftSum=0;
        int rightSum=0;

        int leftQ=0;
        int rightQ=0;

        for (int i=0;i<n;i++) {
            if(s[i]=='?'){
                if(i<n/2) leftQ++;
                else rightQ++;
            }
            else{
                 if(i<n/2) leftSum+=(s[i]-'0');
                else rightSum+=(s[i]-'0');
            }
        }
        
        if((leftQ+rightQ) %2 ==1) return true;

        int left= 2*leftSum + 9*leftQ;
        int right= 2*rightSum + 9*rightQ;

        return !(left==right);
    }
};