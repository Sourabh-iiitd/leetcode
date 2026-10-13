class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> out;

        for(auto path: paths){
            out.insert(path[0]);
        }
        for (auto path : paths) {
            if (out.find(path[1])==out.end()) {
                return path[1];
            }
        }
        
        return "";
    }
};