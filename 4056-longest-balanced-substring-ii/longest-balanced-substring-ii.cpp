class Solution {
public:
    int one(string &s){
        if(s.empty()) return 0;
        int cnt=1;
        int ans=1;
        for(int i=1; i<s.size(); i++){
            if(s[i] == s[i - 1]) cnt++;
            else cnt=1;
            ans=max(ans, cnt);
        }
        return ans;
    }
    int two(string &s , char a , char b){
        map<int, int> mpp;
    
        int cnt1=0;
        int cnt2=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=a && s[i]!=b){
                mpp.clear();
                cnt1=0;
                cnt2=0;
                continue;
            }
            if(s[i]==a){
                cnt1++;
            }
            if(s[i]==b){
                cnt2++;
            }
            if(cnt1==cnt2) ans=max(ans,cnt1+cnt2);

            if(mpp.find(cnt1-cnt2) != mpp.end()){
                ans = max(ans, i - mpp[cnt1-cnt2]);
            }
            else{
                mpp[cnt1-cnt2] = i;
            }
            
        }
        return ans;
    }
    int three(string &s, char a, char b, char c){
        int cnt1=0;
        int cnt2=0;
        int cnt3=0;
        int ans=0;
        unordered_map<string,int> mpp;
        for(int i=0;i<s.size();i++){
            if(s[i]==a) cnt1++;
            if(s[i]==b) cnt2++;
            if(s[i]==c) cnt3++;
            if(cnt1==cnt2 && cnt2==cnt3) {
                ans=max(ans, cnt1+cnt2+cnt3);
            }
            int diff1=cnt1-cnt2;
            int diff2=cnt1-cnt3;
            string key= to_string(diff1)+"_"+to_string(diff2);
            if(mpp.count(key)) ans=max(ans,i-mpp[key]);
            else mpp[key]=i;
        }
        return ans;
    }
    int longestBalanced(string s) {
        int ans=0;
        ans=max({one(s),
        two(s,'a','b'), two(s,'b', 'c'), two(s, 'a', 'c'),
        three(s,'a','b','c')});
        return ans;
    }
};