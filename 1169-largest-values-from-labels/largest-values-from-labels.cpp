class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n=values.size();
        vector<pair<int,int>> items(n);

        for(int i =0;i<n;i++){
            items[i]={values[i],labels[i]};
        }
        sort(items.begin(), items.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });

        unordered_map<int,int> labelCount;
        int maxi=0;
        int selcnt=0;

        for(auto item:items){
            int val=item.first;
            int label= item.second;

            if(labelCount[label]< useLimit){
                maxi+=val;
                labelCount[label]++;
                selcnt++;

                if(selcnt== numWanted) break;
            }
        }
        return maxi;
    }
};