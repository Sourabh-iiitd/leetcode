class Solution {
public:

    int openLock(vector<string>& deadends, string target) {
        int n=deadends.size();
        unordered_set<string> st(deadends.begin(),deadends.end());
        if(st.contains("0000")) return -1;
        
        queue<pair<string,int>> q;
        q.push({"0000",0});

        
        st.insert("0000");

        while(!q.empty()){
            string curr=q.front().first;
            int steps=q.front().second;    
            q.pop();
            if(curr==target) return steps;
            string og=curr;
            for(int i=0;i<4;i++){
                string temp = curr;
                temp[i] = (curr[i] == '9') ? '0' : curr[i] + 1;
                if(!st.contains(temp)) q.push({temp, steps + 1});
                if(!st.contains(temp)) st.insert(temp);

                temp = curr;

               //dec
                temp[i] = (curr[i] == '0') ? '9' : curr[i] - 1;
                if(!st.contains(temp)) q.push({temp, steps + 1});
                if(!st.contains(temp)) st.insert(temp);
                
            }
            
        }
        return -1;
    }
};