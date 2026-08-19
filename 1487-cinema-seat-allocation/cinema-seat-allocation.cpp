class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
       
        unordered_map<int, vector<int>> rowSeats;
        for (const auto& seat : reservedSeats) {
            int row=seat[0];
            int col=seat[1];
            if (col >= 2 && col <= 9) {
                rowSeats[row].push_back(col);
            }
        }
        
      
        int ans=n*2;
        
      
        for (const auto& [row, seats] : rowSeats) {
            bool left=true;   
            bool right=true; 
            bool middle=true; 
            
            for (int col : seats) {
                if (col == 2 || col == 3) left=false;
                if (col == 4 || col == 5) { left=false; middle=false; }
                if (col == 6 || col == 7) { right=false; middle=false; }
                if (col == 8 || col == 9) right=false;
            }
            
            if (left && right) {
               
                continue;
            } else if (left || right || middle) {
               
                ans -= 1;
            } else {
                
                ans -= 2;
            }
        }
        
        return ans;
    }
};