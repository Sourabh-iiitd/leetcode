class Solution {
public:
    int countValidPrefixes(string s) {
        vector<int> ones(s.size(),0);
        vector<int> zeroes(s.size(),0);
        if(s[0]=='1') ones[0]=1;
        if(s[0]=='0') zeroes[0]=1;
        for(int i=1;i<s.size();i++){
            int curr_0=zeroes[i-1];
            int curr_1=ones[i-1];
            if(s[i]=='0') curr_0++;
            else if(s[i]=='1') curr_1++;
            ones[i]=curr_1;
            zeroes[i]=curr_0;
        }
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(abs(ones[i]-zeroes[i])<=1) ans++;
        }
        return ans;
        
    }
};