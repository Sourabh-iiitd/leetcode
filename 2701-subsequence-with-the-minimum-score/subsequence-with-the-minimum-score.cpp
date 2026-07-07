class Solution {
public:
    bool sub(string s, string t){
        int i=0;
        int j=0;
        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]){
                i++;
            }
            j++;
        }
        return i==s.size();

    }
    int minimumScore(string s, string t) {
     
        if(sub(t,s)) return 0;

        int n=s.size();
        int m=t.size();

        vector<int> left(m ,-1);
        vector<int> right(m , n);

        int j=0;
        for(int i=0;i<m;i++){
            while(j<n && s[j]!=t[i]){
                j++;

            }
            if(j<n){
                left[i]=j;
                j++;
            }
            else{
                break;
            }
        }
        int j2=n-1;
        for(int i=m-1;i>=0;i--){
            while(j2>=0 && s[j2]!=t[i]){
                j2--;

            }
            if(j2>=0){
                right[i]=j2;
                j2--;
            }
            else{
                break;
            }
        }
        int ans=m;
        for (int i = 0; i < m; i++) {
            if (left[i] != -1) {
                ans = min(ans, m - 1 - i); 
            }
            if (right[i] != n) {
                ans = min(ans, i);   
            }
        }
        int r = 0;
        for (int l = 0; l < m; l++) {
            if (left[l] == -1) break;
    
    
            while (r < m && (right[r] == n || left[l] >= right[r])) {
                r++;
            }
            if (r < m) {
                ans = min(ans, r - l - 1);
            }
        }

        return ans;

    }
};