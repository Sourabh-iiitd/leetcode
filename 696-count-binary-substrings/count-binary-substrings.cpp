class Solution{
public:
    int countBinarySubstrings(string s){
        vector<int> c;
        int i=0;
        int n=s.size();

        while(i<n){
            int count=0;
            char curr=s[i];

            while(i<n && s[i]==curr){
                count++;
                i++;
            }

            c.push_back(count);
        }

        int ans=0;
        for(int i=1; i<c.size(); i++){
            ans += min(c[i], c[i-1]);
        }

        return ans;
    }
};
