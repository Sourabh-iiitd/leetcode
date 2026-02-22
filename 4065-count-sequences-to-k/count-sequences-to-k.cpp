class Solution {
public:
    int n;
    unordered_map<string, int> mp;
    int helper(vector<int>& a, long long k, int i, long long nm,long long dn) {
        if(i==n) {
            if (nm/dn==k && nm % dn==0) return 1;
            return 0;
        }
        long long gcd=__gcd(nm, dn);

        //geneating my unique string
        string s=to_string(nm/gcd)+"X" + to_string(dn/gcd) + "X" +
                   to_string(i * 100 + 7)+"XX";

        if (mp.find(s)!=mp.end())
            return mp[s];

        int ans=0;
       
        ans+=helper(a, k, i + 1, nm * a[i], dn);
       
        ans+=helper(a, k, i + 1, nm, dn * a[i]);

        ans+=helper(a, k, i + 1, nm, dn);
        return mp[s]=ans;
    }
    int countSequences(vector<int>& a, long long k) {
        mp.clear();

        n=a.size();
        return helper(a, k, 0, 1, 1);
    }
};