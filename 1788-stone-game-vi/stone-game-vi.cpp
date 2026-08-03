class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();

        vector<pair<int,int>> v;

        for(int i=0;i<n;i++)
            v.push_back({aliceValues[i]+bobValues[i], i});

        sort(v.rbegin(), v.rend());

        int a = 0, b = 0;

        for(int i=0;i<n;i++){
            int idx = v[i].second;
            if(i%2==0)
                a += aliceValues[idx];
            else
                b += bobValues[idx];
        }

        if(a>b) return 1;
        if(a<b) return -1;
        return 0;
    }
};