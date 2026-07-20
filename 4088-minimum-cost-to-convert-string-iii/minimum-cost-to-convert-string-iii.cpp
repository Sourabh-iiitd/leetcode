class Solution {
public:
    vector<int> costs;
    string source;
    string target;
    vector<vector<string>> rules;
    vector<int> dp;
    int this_cost(int idx,string &pattern, string &replacement){
        string sub_source=source.substr(idx,pattern.size());
        string sub_target=target.substr(idx,pattern.size());

        if(sub_source.size()!=pattern.size() || sub_target.size()!=replacement.size()) return -1;
        bool check=true;
        int cost=0;
        for(int i=0;i<sub_source.size();i++){
            if(sub_source[i]== pattern[i] ) continue;
         
            else if(pattern[i]=='*') {
                cost++;
                continue;
            }
            check=false;
        }
        if(sub_target!=replacement) check=false;
        return (check==false) ? -1: cost;


    }
    int solve(int idx){
        if(idx>=source.size()) return 0;
        if (dp[idx]!=-2) return dp[idx];
        int cost_ans=INT_MAX;
        for(int i=0;i<rules.size();i++){
            string &pattern=rules[i][0];
            string &replacement=rules[i][1];
            int cst=this_cost(idx,pattern,replacement);
            if(cst==-1) continue;
            cst+=costs[i];
            int next_cost=solve(idx+pattern.size());
            if(next_cost==-1) continue;
            
            cost_ans=min(cost_ans, cst+next_cost);

        }

        if(source[idx]==target[idx]){
            int next=solve(idx+1);
            if(next!=-1) cost_ans= min(cost_ans, next);
        }
        
        if(cost_ans==INT_MAX) return dp[idx]=-1;
        return dp[idx]= cost_ans;

    }
    int minCost(string source, string target, vector<vector<string>>& rules, vector<int>& costs) {
        if(source==target) return 0;
        dp.assign(source.size()+1,-2);
        this->source=source;
        this->costs=costs;
        this->target=target;
        this->rules=rules;
        return solve(0);
    }
};