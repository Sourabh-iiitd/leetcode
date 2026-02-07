class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev = -1;
        int n = s.size();
        
        for(int i=0;i<n;i++){
            
            if(isdigit(s[i])){
                int curr = 0;
                
              
                while(i<n && isdigit(s[i])){
                    curr = curr*10 + (s[i]-'0');
                    i++;
                }
                
                if(curr <= prev) return false;
                
                prev = curr;
            }
        }
        
        return true;
    }
};
