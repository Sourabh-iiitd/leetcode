class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int ans = 0;

        string st = "";  

        for(char c : directions){
            
            if(c == 'R'){
                st.push_back(c);
            }
            else if(c == 'S'){
                while(!st.empty() && st.back() == 'R'){
                    ans++;
                    st.pop_back();
                }
                st.push_back('S');
            }
            else { 
                if(st.empty()){
                    continue;
                }
                else if(st.back() == 'S'){
                    ans++; 
                }
                else{ 
                    
                    ans += 2;
                    st.pop_back();
                    while(!st.empty() && st.back() == 'R'){
                        ans++;
                        st.pop_back();
                    }
                }
                st.push_back('S');
            }
        }

        return ans;
    }
};