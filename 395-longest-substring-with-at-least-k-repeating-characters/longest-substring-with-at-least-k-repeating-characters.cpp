class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.size();
        if(n==0 || n<k) return 0;
        unordered_map<char, int> freq;
        for(char c:s) freq[c]++;

        for(int i=0;i<n;i++){
            if(freq[s[i]]<k){
                //split iske around
                int left=longestSubstring(s.substr(0,i),k);
                
                int next=i+1;
                while(next<n && freq[s[next]]<k) next++;

                int right= longestSubstring(s.substr(next),k);

                return max(left,right);
            }
        }
        return n;
    }
};