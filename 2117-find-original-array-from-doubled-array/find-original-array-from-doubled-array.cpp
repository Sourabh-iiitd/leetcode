class Solution{
public:
    unordered_map<int,int> freq;

    void solve(int i, vector<int>& changed, vector<int>& ans){
        if (i==changed.size()) return;

        int x=changed[i];

        
        if (freq[x]>0){
            freq[x]--;
            if (freq[2*x] > 0){
                freq[2*x]--;
                ans.push_back(x);
            }
        }
        solve(i+1,changed,ans);
    }

    vector<int> findOriginalArray(vector<int>& changed){
        int n = changed.size();
        if (n%2!=0) return{};

        sort(changed.begin(), changed.end());

       
        for (int x:changed){
            freq[x]++;
        }

        vector<int> ans;
        solve(0, changed, ans);

       
        if (ans.size()==n/2){
            return ans;
        }
        return{};
    }
};