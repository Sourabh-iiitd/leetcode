class Solution {
public:
    
    int mirrorFrequency(string s) {
        unordered_map<char,int> mpp;
        bool visited[128] = {false};
        int ans=0;
        for(int i=0;i<s.size();i++){
            char chk=s[i];
            mpp[chk]++;

        }

        for(int i=0;i<s.size();i++){
            if(visited[s[i]]) continue;
            // for(auto it:mpp){
                int res=0;
                int freq_c=mpp[s[i]];
                int freq_m=0;
                char mirror;
                if(s[i]>='a' && s[i]<='z'){
                    mirror='z'-(s[i]-'a');
                }else{
                    mirror='9'-(s[i]-'0');
                }
                visited[mirror] = true;
                visited[s[i]] = true;
                freq_m=mpp[mirror];
                res=abs(freq_c-freq_m);
                ans+=res;
            // }

        }
        

        return ans;
    }
};