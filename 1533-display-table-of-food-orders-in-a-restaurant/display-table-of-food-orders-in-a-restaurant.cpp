class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
       
        map<int, map<string, int>> tableOrders;
        
        
        set<string> foodItems;

      
        for(auto& order : orders) {
            int tableID = stoi(order[1]); 
            string food = order[2];
            
            tableOrders[tableID][food]++;
            foodItems.insert(food);
        }

        
        vector<vector<string>> ans;
        
       
        vector<string> header;
        header.push_back("Table");
        for(const string& food : foodItems) {
            header.push_back(food);
        }
        ans.push_back(header);

       
        for(auto& [id, orderMap] : tableOrders) {
            vector<string> row;
            row.push_back(to_string(id)); 
            
            
            for(const string& food : foodItems) {
                
                row.push_back(to_string(orderMap[food])); 
            }
            ans.push_back(row);
        }

        return ans;
    }
};