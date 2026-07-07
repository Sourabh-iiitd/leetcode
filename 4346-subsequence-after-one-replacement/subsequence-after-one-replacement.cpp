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
    bool canMakeSubsequence(string s, string t) {
        if(s.size()>t.size()) return false;
        if(sub(s,t)) return true;

        int n=s.size();
        int m=t.size();

        vector<int> left(n ,-1);
        vector<int> right(n , m);

        int j=0;
        for(int i=0;i<n;i++){
            while(j<m && t[j]!=s[i]){
                j++;

            }
            if(j<m){
                left[i]=j;
                j++;
            }
            else{
                break;
            }
        }
        int j2=m-1;
        for(int i=n-1;i>=0;i--){
            while(j2>=0 && t[j2]!=s[i]){
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

        for(int i=0;i<n;i++){
            int L=(i == 0) ? -1 : left[i - 1];
            int R=(i == n - 1) ? m : right[i + 1];
            
            if((i>0 && left[i-1]==-1) || (i<n-1 && right[i+1]==m) ) continue;

            if (R - L > 1) return true;

        }

        return false;



    }
};